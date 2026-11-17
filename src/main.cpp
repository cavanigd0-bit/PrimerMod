#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $(MyMenuLayer, MenuLayer) {
public:
  bool MyLayer::init() {

    auto spr = ButtonSprite::create("Hola");

    auto btn = CCMenuItemExt::createSpriteExtra(spr, nullptr);

    menu->addChild(btn);
  }
}
