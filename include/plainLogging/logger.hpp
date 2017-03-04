//
// Created by benno on 1/18/17.
//

#ifndef PLAINLOGGING_LOGGERV2_HPP
#define PLAINLOGGING_LOGGERV2_HPP

#include <iostream>
#include <array>
#include <vector>
#include <mutex>
#include <thread>
#include <fstream>
#include <experimental/string_view>
#include <chrono>
#include <ctime>

#define LOG_DEBUG( STRING )
#define LOG_WARNING( STRING )
#define LOG_ERROR( STRING )

// set default logMessage length if no length was defined
#ifndef LOG_STRING_LENGTH
#define LOG_STRING_LENGTH 60
#endif

// ##########################################################################################################################################
// ##########################################################################################################################################
// ##########################################################################################################################################
namespace GonLog {
    enum class logLevel {
        DEBUG,
        WARNING,
        ERROR
    };

    class GonLogClass
    {
        struct logEntry {
            char message[LOG_STRING_LENGTH];
            size_t id;
            logLevel level;
            std::chrono::time_point<std::chrono::system_clock> time;
        };

        // private variables
        static constexpr size_t m_QUEUE_Length{10};
        logEntry m_logEntriesStack[m_QUEUE_Length];
        size_t m_iQueueWrite{0};
        size_t m_iQueueRead = {0};
        std::mutex m_stackLock;
        std::thread m_logWriter;
        size_t m_idGen{0};
        std::string m_htmlOutput;
        bool bRunThread{true};
        std::string m_logFilePath{"log.html"};


        // private functions
        void writeLog();
        static void logWriterFunction();

    public:
        GonLogClass();
        ~GonLogClass();

        // log functions
        void log(std::experimental::basic_string_view<char> errorString, logLevel level);
        void setLogFilePath(const std::string &m_logFilePath);

    } GonLogSingleton;

    // ##########################################################################################################################################
    // ##########################################################################################################################################
    // ##########################################################################################################################################

    GonLogClass::GonLogClass() {
        std::time_t tTime = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
        std::string outTime = std::string( std::ctime( &tTime ));
        outTime.pop_back();
        m_htmlOutput +=
                "<Comment " + outTime + ">\n"
                "<!DOCTYPE html> \n"
                "<html lang=\"en\"> \n"
                "   <head> \n"
                "       <meta charset=\"UTF-8\"> \n"
                "       <title>Log Jan 17</title> \n"
                "           <style> \n"
                "               .DEBUG { color: white } \n"
                "               .WARNING { color: yellow } \n"
                "               .ERROR { color: red } \n"
                "               body { background-color: darkgray } \n"
                "           </style> \n"
                "   </head> \n"
                "   <body> \n";

        m_logWriter = std::thread(logWriterFunction);
    }

    GonLogClass::~GonLogClass() {
        // tell log writer to stop and wait for finish to empty stack queue
        bRunThread = false;
        m_logWriter.join();

        // write out log file
        writeLog();
    }

    void GonLogClass::log(std::experimental::basic_string_view<char> errorString, logLevel level) {
        // get length of the error message
        size_t length{errorString.length() + 1};

        // increment write index thread safe
        m_stackLock.lock();
        size_t stackIndex = m_iQueueWrite++;
        m_iQueueWrite %= m_QUEUE_Length;
        m_stackLock.unlock();

        // set entry id
        m_logEntriesStack[stackIndex].id = m_idGen++;
        m_logEntriesStack[stackIndex].level = level;
        m_logEntriesStack[stackIndex].time = std::chrono::system_clock::now();

        if (length <= LOG_STRING_LENGTH) {
            std::copy(errorString.begin(), errorString.end(), &m_logEntriesStack[stackIndex].message[0]);
            m_logEntriesStack[stackIndex].message[length - 1] = '\0';
            m_stackLock.unlock();
        } else    // LOG message was too long to be logged
        {
            // copy string to qualified length and add terminating character
            std::copy(errorString.begin(), errorString.begin()+LOG_STRING_LENGTH-2, &m_logEntriesStack[stackIndex].message[0]); // -1 at end() should work too
            m_logEntriesStack[stackIndex].message[LOG_STRING_LENGTH - 1] = '\0';

            m_stackLock.unlock();

            std::string message{"Warning id" + std::to_string(m_logEntriesStack[stackIndex].id) + " was too long"};
            log(&message[0], logLevel::WARNING);
        }
    }

    void GonLogClass::logWriterFunction()
    {
        while ( !( !GonLogSingleton.bRunThread && GonLogSingleton.m_iQueueWrite - GonLogSingleton.m_iQueueRead == 0 ) )
        {
            std::this_thread::yield();

            while ( GonLogSingleton.m_iQueueWrite - GonLogSingleton.m_iQueueRead != 0 ) {
                size_t currentStackIndex = GonLogSingleton.m_iQueueRead++;
                GonLogSingleton.m_iQueueRead %= GonLogSingleton.m_QUEUE_Length;

                // open entry
                switch (GonLogSingleton.m_logEntriesStack[currentStackIndex].level) {
                    case logLevel::DEBUG:
                        GonLogSingleton.m_htmlOutput += "\t\t<p class=\"DEBUG\" ";
                        break;
                    case logLevel::WARNING:
                        GonLogSingleton.m_htmlOutput += "\t\t<p class=\"WARNING\" ";
                        break;
                    case logLevel::ERROR:
                        GonLogSingleton.m_htmlOutput += "\t\t<p class=\"ERROR\" ";
                        break;
                }

                // write attributes
                GonLogSingleton.m_htmlOutput += "ID=\"" + std::to_string( GonLogSingleton.m_logEntriesStack[currentStackIndex].id ) + "\" ";

                std::time_t tTime = std::chrono::system_clock::to_time_t( GonLogSingleton.m_logEntriesStack[currentStackIndex].time );
                std::string outTime = std::string( std::ctime( &tTime ));
                outTime.pop_back();
                GonLogSingleton.m_htmlOutput += "DATE=\"" + outTime + "\" ";

                // close entry
                GonLogSingleton.m_htmlOutput += ">\n";
                GonLogSingleton.m_htmlOutput += "\t\t\t\"" + std::string{GonLogSingleton.m_logEntriesStack[currentStackIndex].message} + "\"\n";
                GonLogSingleton.m_htmlOutput += "\t\t</p>\n";
            }
        }
    }

    void GonLogClass::writeLog() {
        std::ofstream log{ m_logFilePath };
        log << m_htmlOutput + "\t</body>\n</html>";
        log.close();
    }

    void GonLogClass::setLogFilePath(const std::string &m_logFilePath) {
        GonLogClass::m_logFilePath = m_logFilePath;
    }
}

#ifdef DEBUG_MODE
#undef LOG_DEBUG
#define LOG_DEBUG( STRING ) \
    { \
        GonLog::GonLogSingleton.log( STRING, GonLog::logLevel::DEBUG ); \
    }
#undef LOG_WARNING
#define LOG_WARNING( STRING ) \
    { \
        GonLog::GonLogSingleton.log( STRING, GonLog::logLevel::WARNING ); \
    }
#undef LOG_ERROR
#define LOG_ERROR( STRING ) \
    { \
        GonLog::GonLogSingleton.log( STRING, GonLog::logLevel::ERROR ); \
    }
#endif

#endif //PLAINLOGGING_LOGGERV2_HPP