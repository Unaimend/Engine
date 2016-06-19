#include "../../include/eventSystem/Event.h"

eng::Event::Event(const std::string& EventName, std::initializer_list<std::string> identifiers, std::initializer_list<Variant> args)
{
    //Konvertiere String zu Hash um schneller zu vergleichen
    mEventName = eng::util::toHash(EventName);
    //In der map hat jeder arg(variable) einen identifier(variablenname) d.h. wenn die nciht gleich gross sind
    //fehlt etwas
    if(identifiers.size() != args.size())
    {
        std::cerr << "initializer_list do need to have the same size" << std::endl;
        exit(-1);
    }
    
    auto it = identifiers.begin();
    auto it2 = args.begin();
    //Jedem Identifiert ein arg zuweisen.
    for(; it < identifiers.end(); ++it, ++it2)
    {
        mArgs[*it] = *it2;
    }
}

eng::hash eng::Event::getHash()
{
    return mEventName;
}