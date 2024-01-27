
#include <Geode/Geode.hpp>
// #include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(buttonHandler, MenuLayer){
	bool init() {
		if (!MenuLayer::init()) return false;

		auto menuLayer = this->getChildByID("side-menu");
		auto spr = CCSprite::create("EminemButton.png"_spr);
    	auto btn = CCMenuItemSpriteExtra::create(
       		spr, this, menu_selector(buttonHandler::onButtonClick)
    	);

		btn->setPosition(42.f, 53.f);
		menuLayer->addChild(btn);

		return true;
	}

	void onButtonClick(CCObject* sender) {
		auto value = Mod::get()->getSettingValue<bool>("toggle");

		if (value)
		{
			geode::createQuickPopup(
			"gey test",
			"eri gey?",
			"ci", "non",
			[](bool btn1, bool btn2) {
				if (btn2) {
					log::info("Btn2");
					FLAlertLayer::create("gey test", "felisidades, no sos un homo disfruta de tu eterosexualidad", "Aceptar")->show();
					return;
				}
				log::info("Btn1");
				FLAlertLayer::create("gey test", "sos un homo ve a succionar una pinga loka", "Aceptar")->show();
			});
		} else {
			geode::createQuickPopup(
			"Gey Test",
			"Are u gey?",
			"Yes", "No",
			[](bool btn1, bool btn2) {
				if (btn2) {
					log::info("Btn2");
					FLAlertLayer::create("Gey Test", "Congratulations, you are not a homo, enjoy your heterosexuality", "Ok")->show();
					return;
				}
				log::info("Btn1");
				FLAlertLayer::create("Gey Test", "You're a homo, go suck crazy dick", "Ok")->show();
			});
		}
		
	}
};
