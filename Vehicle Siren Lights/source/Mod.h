#pragma once

#include "pch.h"

class Mod {
private:
public:
    static bool m_DebugEnabled;
    static bool m_IsSamp;
    static std::string m_Version;

    static void Update();
    static void Draw();


    static unsigned int GetDeltaTime();
    static void SetPlayerControl(bool enabled);
    static void ToggleMenu();
    static void ReloadConfig();
    static void DisableOriginalLights();

    Mod();
};
