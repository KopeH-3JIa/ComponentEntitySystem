#include <iostream>
#include <vector>
#include <iterator>
#include <bitset>
#include "entity.h"
#include "component.h"

struct PositionComponent : public Component<PositionComponent> {
  PositionComponent(Entity *entity): Component<PositionComponent>(entity) {}
  float getX() const;
  float getY() const;
  PositionComponent &setX(float value);
  PositionComponent &setY(float value);
  void initialize() {
    std::cout << "PositionComponent init" << std::endl;
  }
private:
  float x;
  float y;
};

struct MoveComponent : public Component<MoveComponent> {
  MoveComponent(Entity *entity): Component<MoveComponent>(entity) {}
  void moveTo(float x,float y){
    position->setX(x).setY(y);
  }
  void initialize() {
    std::cout << "MoveComponent init" << std::endl;
    position = &entity->getComponent<PositionComponent>();
  }
private:
  PositionComponent *position;
};




int main(int , char *[]) {
  Entity dynamicEntity;
  Entity staticEntity;
  dynamicEntity.addComponent<PositionComponent>();
  dynamicEntity.addComponent<MoveComponent>();
  dynamicEntity.getComponent<MoveComponent>().moveTo(10,10);

  staticEntity.addComponent<PositionComponent>();

  std::cout<<"Dynamic: "
          << dynamicEntity.getComponent<PositionComponent>().getX() << " "
          << dynamicEntity.getComponent<PositionComponent>().getY()
          << std::endl;

  std::cout<<"Static: "
          << staticEntity.getComponent<PositionComponent>().getX() << " "
          << staticEntity.getComponent<PositionComponent>().getY()
          << std::endl;
  return 0;
}





























float PositionComponent::getX() const {
  return x;
}

PositionComponent &PositionComponent::setX(float value) {
  x = value;
  return *this;
}
float PositionComponent::getY() const {
  return y;
}

PositionComponent &PositionComponent::setY(float value) {
  y = value;
  return *this;
}

