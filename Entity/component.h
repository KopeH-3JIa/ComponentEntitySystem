#ifndef COMPONENT_H
#define COMPONENT_H

#include <functional>
#include <vector>
#include <map>
#include <bitset>
#include <assert.h>

using ComponentId = std::size_t;
class Entity;

class BaseComponent{
public:
    static const ComponentId MAX_ID{32u};
    virtual ~BaseComponent(){}
protected:
};
namespace {
static inline size_t __getUniqueId() noexcept {
    static size_t id{static_cast<size_t>(-1)};
    assert(id+1 <= BaseComponent::MAX_ID && "Maximum component id!");
    return ++id;
}
}

template<typename T>
class Component: public BaseComponent{
public:
    Component(Entity *entity):entity(entity){}
    void initialize(){
      static_cast<T*>(this)->initialize();
    }
protected:
    Entity *entity;
};

template<typename T>
inline ComponentId getComponentTypeId() noexcept{
    static_assert(std::is_base_of<Component<T>,T>::value,"T must inherit from Component");
    static ComponentId id = __getUniqueId();
    return id;
}

using ComponentArray = std::map<ComponentId,BaseComponent*>;
#endif // COMPONENT_H
