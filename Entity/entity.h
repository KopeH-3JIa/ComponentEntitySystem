#ifndef ENTITY_H
#define ENTITY_H
#include <memory>
#include <functional>
#include "component.h"
class Entity
{
public:
    Entity();
    ~Entity();

    template <typename T,typename... TArgs>
    T& addComponent(TArgs &&... args)noexcept{
        T* c(new T(this,std::forward<TArgs>(args)...));
        components[getComponentTypeId<T>()] = c;
        return *c;
    }
    template <typename T>
    T& addComponent() noexcept{
        T* c(new T(this));
        components[getComponentTypeId<T>()] = c;
        c->initialize();
        return *c;
    }
    template <typename T>
    bool hasComponent() const noexcept{
        return components.count(getComponentTypeId<T>());
    }

    template <typename T>
    T&  getComponent() const noexcept{
      assert(hasComponent<T>() && "Entity don't have this component!");
        return *reinterpret_cast<T*>(components.at(getComponentTypeId<T>()));
    }

private:
    ComponentArray components;
};

#endif // ENTITY_H
