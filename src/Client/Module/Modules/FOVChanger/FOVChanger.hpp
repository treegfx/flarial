#pragma once

#include "../Module.hpp"
#include "../../../Events/EventHandler.hpp"
#include "../../../Client.hpp"

class FOVChanger : public Module {

public:


    FOVChanger() : Module("FOV Changer", "toes x4", "\\Flarial\\assets\\field-of-view.png", 'o') {

        onEnable();

    };

    void onEnable() override {

        Module::onEnable();

		if (settings.getSettingByName<float>("fovvalue") == nullptr) settings.addSetting("fovvalue", 60.00f);

    }

    void onDisable() override {

        Module::onDisable();

    }

    void SettingsRender() override {

		float toggleX = Constraints::PercentageConstraint(0.019, "left");
		float toggleY = Constraints::PercentageConstraint(0.10, "top");

		const float textWidth = Constraints::RelativeConstraint(0.12, "height", true);
		const float textHeight = Constraints::RelativeConstraint(0.029, "height", true);

		FlarialGUI::ScrollBar(toggleX, toggleY, 140, Constraints::SpacingConstraint(5.5, textWidth), 2);
		FlarialGUI::SetScrollView(toggleX, toggleY, Constraints::RelativeConstraint(1.0, "width"), Constraints::RelativeConstraint(0.90, "height"));

		FlarialGUI::FlarialTextWithFont(toggleX, toggleY, L"FOV Value", D2D1::ColorF(D2D1::ColorF::White), textWidth, textHeight, DWRITE_TEXT_ALIGNMENT_LEADING, Constraints::RelativeConstraint(0.12, "height", true));

		float percent = FlarialGUI::Slider(0, toggleX + Constraints::SpacingConstraint(0.7, textWidth),
			toggleY,
			D2D1::ColorF(255.0f / 255.0f, 36.0f / 255.0f, 56.0f / 255.0f),
			D2D1::ColorF(154.0f / 255.0f, 107.0f / 255.0f, 114.0f / 255.0f),
			D2D1::ColorF(D2D1::ColorF::White), this->settings.getSettingByName<float>("fovvalue")->value, 359.0f);

		this->settings.getSettingByName<float>("fovvalue")->value = percent;

		FlarialGUI::UnsetScrollView();
    }
};
