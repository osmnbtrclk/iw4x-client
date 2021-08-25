#include "STDInclude.hpp"

#include <limits>

namespace Game
{
    ButtonToCodeMap_t buttonList[]
    {
        {GPAD_X, K_BUTTON_X},
        {GPAD_A, K_BUTTON_A},
        {GPAD_B, K_BUTTON_B},
        {GPAD_Y, K_BUTTON_Y},
        {GPAD_L_TRIG, K_BUTTON_LTRIG},
        {GPAD_R_TRIG, K_BUTTON_RTRIG},
        {GPAD_L_SHLDR, K_BUTTON_LSHLDR},
        {GPAD_R_SHLDR, K_BUTTON_RSHLDR},
        {GPAD_START, K_BUTTON_START},
        {GPAD_BACK, K_BUTTON_BACK},
        {GPAD_L3, K_BUTTON_LSTICK},
        {GPAD_R3, K_BUTTON_RSTICK},
        {GPAD_UP, K_DPAD_UP},
        {GPAD_DOWN, K_DPAD_DOWN},
        {GPAD_LEFT, K_DPAD_LEFT},
        {GPAD_RIGHT, K_DPAD_RIGHT}
    };

    StickToCodeMap_t analogStickList[4]
    {
        {GPAD_LX, K_APAD_RIGHT, K_APAD_LEFT},
        {GPAD_LY, K_APAD_UP, K_APAD_DOWN},
        {GPAD_RX, K_APAD_RIGHT, K_APAD_LEFT},
        {GPAD_RY, K_APAD_UP, K_APAD_DOWN},
    };

    GamePadStick stickForAxis[GPAD_PHYSAXIS_COUNT]
    {
        GPAD_RX,
        GPAD_RY,
        GPAD_LX,
        GPAD_LY,
        GPAD_INVALID,
        GPAD_INVALID
    };

    GamepadPhysicalAxis axisSameStick[GPAD_PHYSAXIS_COUNT]
    {
        GPAD_PHYSAXIS_RSTICK_Y,
        GPAD_PHYSAXIS_RSTICK_X,
        GPAD_PHYSAXIS_LSTICK_Y,
        GPAD_PHYSAXIS_LSTICK_X,
        GPAD_PHYSAXIS_NONE,
        GPAD_PHYSAXIS_NONE
    };

    const char* physicalAxisNames[GPAD_PHYSAXIS_COUNT]
    {
        "A_RSTICK_X",
        "A_RSTICK_Y",
        "A_LSTICK_X",
        "A_LSTICK_Y",
        "A_RTRIGGER",
        "A_LTRIGGER"
    };

    const char* virtualAxisNames[GPAD_VIRTAXIS_COUNT]
    {
        "VA_SIDE",
        "VA_FORWARD",
        "VA_UP",
        "VA_YAW",
        "VA_PITCH",
        "VA_ATTACK"
    };

    const char* gamePadMappingTypeNames[GPAD_MAP_COUNT]
    {
        "MAP_LINEAR",
        "MAP_SQUARED"
    };

    keyNum_t menuScrollButtonList[]
    {
        K_APAD_UP,
        K_APAD_DOWN,
        K_APAD_LEFT,
        K_APAD_RIGHT,
        K_DPAD_UP,
        K_DPAD_DOWN,
        K_DPAD_LEFT,
        K_DPAD_RIGHT
    };

    keyname_t extendedKeyNames[]
    {
        {"BUTTON_A", K_BUTTON_A},
        {"BUTTON_B", K_BUTTON_B},
        {"BUTTON_X", K_BUTTON_X},
        {"BUTTON_Y", K_BUTTON_Y},
        {"BUTTON_LSHLDR", K_BUTTON_LSHLDR},
        {"BUTTON_RSHLDR", K_BUTTON_RSHLDR},
        {"BUTTON_START", K_BUTTON_START},
        {"BUTTON_BACK", K_BUTTON_BACK},
        {"BUTTON_LSTICK", K_BUTTON_LSTICK},
        {"BUTTON_RSTICK", K_BUTTON_RSTICK},
        {"BUTTON_LTRIG", K_BUTTON_LTRIG},
        {"BUTTON_RTRIG", K_BUTTON_RTRIG},
        {"DPAD_UP", K_DPAD_UP},
        {"DPAD_DOWN", K_DPAD_DOWN},
        {"DPAD_LEFT", K_DPAD_LEFT},
        {"DPAD_RIGHT", K_DPAD_RIGHT},
    };

    keyname_t extendedLocalizedKeyNames[]
    {
        // Material text icons pattern: 0x01 width height material_name_len
        {"^\x01\x32\x32\x08""button_a", K_BUTTON_A},
        {"^\x01\x32\x32\x08""button_b", K_BUTTON_B},
        {"^\x01\x32\x32\x08""button_x", K_BUTTON_X},
        {"^\x01\x32\x32\x08""button_y", K_BUTTON_Y},
        {"^\x01\x32\x32\x0D""button_lshldr", K_BUTTON_LSHLDR},
        {"^\x01\x32\x32\x0D""button_rshldr", K_BUTTON_RSHLDR},
        {"^\x01\x32\x32\x0C""button_start", K_BUTTON_START},
        {"^\x01\x32\x32\x0B""button_back", K_BUTTON_BACK},
        {"^\x01\x48\x32\x0D""button_lstick", K_BUTTON_LSTICK},
        {"^\x01\x48\x32\x0D""button_rstick", K_BUTTON_RSTICK},
        {"^\x01\x32\x32\x0C""button_ltrig", K_BUTTON_LTRIG},
        {"^\x01\x32\x32\x0C""button_rtrig", K_BUTTON_RTRIG},
        {"^\x01\x32\x32\x07""dpad_up", K_DPAD_UP},
        {"^\x01\x32\x32\x09""dpad_down", K_DPAD_DOWN},
        {"^\x01\x32\x32\x09""dpad_left", K_DPAD_LEFT},
        {"^\x01\x32\x32\x0A""dpad_right", K_DPAD_RIGHT},
    };

    constexpr auto VANILLA_KEY_NAME_COUNT = 95;
    constexpr auto VANILLA_LOCALIZED_KEY_NAME_COUNT = 95;
    keyname_t combinedKeyNames[VANILLA_KEY_NAME_COUNT + std::extent_v<decltype(extendedKeyNames)> + 1];
    keyname_t combinedLocalizedKeyNames[VANILLA_KEY_NAME_COUNT + std::extent_v<decltype(extendedLocalizedKeyNames)> + 1];

    PlayerKeyState* playerKeys = reinterpret_cast<PlayerKeyState*>(0xA1B7D0);
    AimAssistGlobals* aaGlobArray = reinterpret_cast<AimAssistGlobals*>(0x7A2110);
    keyname_t* vanillaKeyNames = reinterpret_cast<keyname_t*>(0x798580);
    keyname_t* vanillaLocalizedKeyNames = reinterpret_cast<keyname_t*>(0x798880);

    constexpr auto VANILLA_AIM_ASSIST_GRAPH_COUNT = 4u;
    GraphFloat* aaInputGraph = reinterpret_cast<GraphFloat*>(0x7A2FC0);
}

namespace Components
{
    Gamepad::GamePad Gamepad::gamePads[Game::MAX_GAMEPADS]{};
    Gamepad::GamePadGlobals Gamepad::gamePadGlobals[Game::MAX_GAMEPADS]{{}};
    int Gamepad::gamePadBindingsModifiedFlags = 0;

    Dvar::Var Gamepad::gpad_enabled;
    Dvar::Var Gamepad::gpad_debug;
    Dvar::Var Gamepad::gpad_present;
    Dvar::Var Gamepad::gpad_in_use;
    Dvar::Var Gamepad::gpad_sticksConfig;
    Dvar::Var Gamepad::gpad_buttonConfig;
    Dvar::Var Gamepad::gpad_menu_scroll_delay_first;
    Dvar::Var Gamepad::gpad_menu_scroll_delay_rest;
    Dvar::Var Gamepad::gpad_rumble;
    Dvar::Var Gamepad::gpad_stick_pressed_hysteresis;
    Dvar::Var Gamepad::gpad_stick_pressed;
    Dvar::Var Gamepad::gpad_stick_deadzone_max;
    Dvar::Var Gamepad::gpad_stick_deadzone_min;
    Dvar::Var Gamepad::gpad_button_deadzone;
    Dvar::Var Gamepad::gpad_button_rstick_deflect_max;
    Dvar::Var Gamepad::gpad_button_lstick_deflect_max;
    Dvar::Var Gamepad::input_viewSensitivity;
    Dvar::Var Gamepad::input_invertPitch;
    Dvar::Var Gamepad::aim_turnrate_pitch;
    Dvar::Var Gamepad::aim_turnrate_pitch_ads;
    Dvar::Var Gamepad::aim_turnrate_yaw;
    Dvar::Var Gamepad::aim_turnrate_yaw_ads;
    Dvar::Var Gamepad::aim_accel_turnrate_enabled;
    Dvar::Var Gamepad::aim_accel_turnrate_lerp;
    Dvar::Var Gamepad::aim_input_graph_enabled;
    Dvar::Var Gamepad::aim_input_graph_index;
    Dvar::Var Gamepad::aim_scale_view_axis;
    Dvar::Var Gamepad::cl_bypassMouseInput;
    Dvar::Var Gamepad::cg_mapLocationSelectionCursorSpeed;

    Dvar::Var Gamepad::xpadSensitivity;
    Dvar::Var Gamepad::xpadEarlyTime;
    Dvar::Var Gamepad::xpadEarlyMultiplier;
    Dvar::Var Gamepad::xpadHorizontalMultiplier;
    Dvar::Var Gamepad::xpadVerticalMultiplier;
    Dvar::Var Gamepad::xpadAdsMultiplier;

    struct ControllerMenuKeyMapping
    {
        Game::keyNum_t controllerKey;
        Game::keyNum_t pcKey;
    };

    ControllerMenuKeyMapping controllerMenuKeyMappings[]
    {
        {Game::K_BUTTON_A, Game::K_ENTER},
        {Game::K_BUTTON_START, Game::K_ENTER},
        {Game::K_BUTTON_B, Game::K_ESCAPE},
        {Game::K_BUTTON_BACK, Game::K_ESCAPE},
        {Game::K_DPAD_UP, Game::K_UPARROW},
        {Game::K_APAD_UP, Game::K_UPARROW},
        {Game::K_DPAD_DOWN, Game::K_DOWNARROW},
        {Game::K_APAD_DOWN, Game::K_DOWNARROW},
        {Game::K_DPAD_LEFT, Game::K_LEFTARROW},
        {Game::K_APAD_LEFT, Game::K_LEFTARROW},
        {Game::K_DPAD_RIGHT, Game::K_RIGHTARROW},
        {Game::K_APAD_RIGHT, Game::K_RIGHTARROW},
    };

    Gamepad::GamePadGlobals::GamePadGlobals()
        : axes{},
          nextScrollTime(0)
    {
        for (auto& virtualAxis : axes.virtualAxes)
        {
            virtualAxis.physicalAxis = Game::GPAD_PHYSAXIS_NONE;
            virtualAxis.mapType = Game::GPAD_MAP_NONE;
        }
    }

    __declspec(naked) void Gamepad::MSG_WriteDeltaUsercmdKeyStub()
    {
        __asm
        {
            // fix stack pointer
            add esp, 0Ch

            // put both forward move and rightmove values in the movement button
            mov dl, byte ptr[edi + 1Ah] // to_forwardMove
            mov dh, byte ptr[edi + 1Bh] // to_rightMove

            mov[esp + 30h], dx // to_buttons

            mov dl, byte ptr[ebp + 1Ah] // from_forwardMove
            mov dh, byte ptr[ebp + 1Bh] // from_rightMove

            mov[esp + 2Ch], dx // from_buttons

            // return back
            push 0x60E40E
            retn
        }
    }

    void Gamepad::ApplyMovement(Game::msg_t* msg, int key, Game::usercmd_s* from, Game::usercmd_s* to)
    {
        char forward;
        char right;

        if (Game::MSG_ReadBit(msg))
        {
            short movementBits = static_cast<short>(key ^ Game::MSG_ReadBits(msg, 16));

            forward = static_cast<char>(movementBits);
            right = static_cast<char>(movementBits >> 8);
        }
        else
        {
            forward = from->forwardmove;
            right = from->rightmove;
        }

        to->forwardmove = forward;
        to->rightmove = right;
    }

    __declspec(naked) void Gamepad::MSG_ReadDeltaUsercmdKeyStub()
    {
        __asm
        {
            push ebx // to
            push ebp // from
            push edi // key
            push esi // msg
            call ApplyMovement
            add esp, 10h

            // return back
            push 0x4921BF
            ret
        }
    }

    __declspec(naked) void Gamepad::MSG_ReadDeltaUsercmdKeyStub2()
    {
        __asm
        {
            push ebx // to
            push ebp // from
            push edi // key
            push esi // msg
            call ApplyMovement
            add esp, 10h

            // return back
            push 3
            push esi
            push 0x492085
            ret
        }
    }

    bool Gamepad::GPad_Check(const int gamePadIndex, const int portIndex)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        if (XInputGetCapabilities(portIndex, XINPUT_FLAG_GAMEPAD, &gamePad.caps) == ERROR_SUCCESS)
        {
            gamePad.enabled = true;
            gamePad.portIndex = portIndex;
            return true;
        }

        gamePad.enabled = false;
        return false;
    }

    void Gamepad::GPad_RefreshAll()
    {
        auto currentGamePadNum = 0;

        for (auto currentPort = 0; currentPort < XUSER_MAX_COUNT && currentGamePadNum < Game::MAX_GAMEPADS; currentPort++)
        {
            if (GPad_Check(currentGamePadNum, currentPort))
                currentGamePadNum++;
        }
    }

    float Gamepad::LinearTrack(const float target, const float current, const float rate, const float deltaTime)
    {
        const auto err = target - current;
        float step;
        if(err <= 0.0f)
            step = -rate * deltaTime;
        else
            step = rate * deltaTime;

        if(std::fabs(err) <= 0.001f)
            return target;

        if (std::fabs(step) <= std::fabs(err))
            return current + step;

        return target;
    }

    void Gamepad::AimAssist_CalcAdjustedAxis(const Game::AimInput* input, float* pitchAxis, float* yawAxis)
    {
        assert(input);
        assert(pitchAxis);
        assert(yawAxis);

        const auto graphIndex = aim_input_graph_index.get<int>();
        if(aim_input_graph_enabled.get<bool>() && graphIndex >= 0 && graphIndex < Game::VANILLA_AIM_ASSIST_GRAPH_COUNT)
        {
            const auto deflection = std::sqrt(input->pitchAxis * input->pitchAxis + input->yawAxis * input->yawAxis);

            float fraction;
            if (deflection - 1.0f < 0.0f)
                fraction = deflection;
            else
                fraction = 1.0f;

            if (0.0f - deflection >= 0.0f)
                fraction = 0.0f;

            const auto graphScale = Game::GraphFloat_GetValue(&Game::aaInputGraph[graphIndex], fraction);
            *pitchAxis = input->pitchAxis * graphScale;
            *yawAxis = input->yawAxis * graphScale;
        }
        else
        {
            *pitchAxis = input->pitchAxis;
            *yawAxis = input->yawAxis;
        }

        if(aim_scale_view_axis.get<bool>())
        {
            const auto absPitchAxis = std::fabs(*pitchAxis);
            const auto absYawAxis = std::fabs(*yawAxis);

            if (absPitchAxis <= absYawAxis)
                *pitchAxis = (1.0f - (absYawAxis - absPitchAxis)) * *pitchAxis;
            else
                *yawAxis = (1.0f - (absPitchAxis - absYawAxis)) * *yawAxis;
        }
    }

    void Gamepad::AimAssist_CalcSlowdown(const Game::AimInput* /*input*/, float* pitchScale, float* yawScale)
    {
        /*assert(input); */
        assert(pitchScale);
        assert(yawScale);

        *pitchScale = 1.0f;
        *yawScale = 1.0f;
    }

    float Gamepad::AimAssist_Lerp(const float from, const float to, const float fraction)
    {
        return (to - from) * fraction + from;
    }

    void Gamepad::AimAssist_ApplyTurnRates(const Game::AimInput* input, Game::AimOutput* output)
    {
        assert(input->localClientNum < Game::MAX_GAMEPADS);
        auto& aaGlob = Game::aaGlobArray[input->localClientNum];

        auto slowdownPitchScale = 0.0f;
        auto slowdownYawScale = 0.0f;
        float adjustedPitchAxis;
        float adjustedYawAxis;

        if(aaGlob.autoMeleeState == Game::AIM_MELEE_STATE_UPDATING)
        {
            adjustedPitchAxis = 0.0f;
            adjustedYawAxis = 0.0f;
            slowdownPitchScale = 1.0f;
            slowdownYawScale = 1.0f;
        }
        else
        {
            AimAssist_CalcAdjustedAxis(input, &adjustedPitchAxis, &adjustedYawAxis);
            AimAssist_CalcSlowdown(input, &slowdownPitchScale, &slowdownYawScale);
        }

        const auto sensitivity = input_viewSensitivity.get<float>();
        auto pitchTurnRate = AimAssist_Lerp(aim_turnrate_pitch.get<float>(), aim_turnrate_pitch_ads.get<float>(), aaGlob.adsLerp);
        pitchTurnRate = slowdownPitchScale * aaGlob.fovTurnRateScale * sensitivity * pitchTurnRate;
        auto yawTurnRate = AimAssist_Lerp(aim_turnrate_yaw.get<float>(), aim_turnrate_yaw_ads.get<float>(), aaGlob.adsLerp);
        yawTurnRate = slowdownYawScale * aaGlob.fovTurnRateScale * sensitivity * yawTurnRate;

        if (input->pitchMax > 0 && input->pitchMax < pitchTurnRate)
            pitchTurnRate = input->pitchMax;
        if (input->yawMax > 0 && input->yawMax < yawTurnRate)
            yawTurnRate = input->yawMax;

        const auto pitchSign = adjustedPitchAxis >= 0.0f ? 1.0f : -1.0f;
        const auto yawSign = adjustedYawAxis >= 0.0f ? 1.0f : -1.0f;

        const auto pitchDelta = std::fabs(adjustedPitchAxis) * pitchTurnRate;
        const auto yawDelta = std::fabs(adjustedYawAxis) * yawTurnRate;
        
        if(!aim_accel_turnrate_enabled.get<bool>())
        {
            aaGlob.pitchDelta = pitchDelta;
            aaGlob.yawDelta = yawDelta;
        }
        else
        {
            const auto accel = aim_accel_turnrate_lerp.get<float>() * sensitivity;
            if (pitchDelta <= aaGlob.pitchDelta)
                aaGlob.pitchDelta = pitchDelta;
            else
                aaGlob.pitchDelta = LinearTrack(pitchDelta, aaGlob.pitchDelta, accel, input->deltaTime);

            if (yawDelta <= aaGlob.yawDelta)
                aaGlob.yawDelta = yawDelta;
            else
                aaGlob.yawDelta = LinearTrack(yawDelta, aaGlob.yawDelta, accel, input->deltaTime);
        }

        output->pitch = aaGlob.pitchDelta * input->deltaTime * pitchSign + output->pitch;
        output->yaw = aaGlob.yawDelta * input->deltaTime * yawSign + output->yaw;
    }

    void Gamepad::AimAssist_UpdateGamePadInput(const Game::AimInput* input, Game::AimOutput* output)
    {
        assert(input->localClientNum < Game::MAX_GAMEPADS);
        auto& aaGlob = Game::aaGlobArray[input->localClientNum];

        output->pitch = input->pitch;
        output->yaw = input->yaw;

        if(aaGlob.initialized)
        {
            Game::AimAssist_UpdateTweakables(input->localClientNum);
            Game::AimAssist_UpdateAdsLerp(input);
            AimAssist_ApplyTurnRates(input, output);

            Game::AimAssist_ApplyAutoMelee(input, output);
        }

        aaGlob.prevButtons = input->buttons;
    }

    void Gamepad::CL_RemoteControlMove_GamePad(const int localClientNum, Game::usercmd_s* cmd)
    {
        // Buttons are already handled by keyboard input handler

        const auto up = CL_GamepadAxisValue(localClientNum, Game::GPAD_VIRTAXIS_FORWARD);
        const auto right = CL_GamepadAxisValue(localClientNum, Game::GPAD_VIRTAXIS_SIDE);
        const auto sensitivity = input_viewSensitivity.get<float>();

        constexpr auto scale = static_cast<float>(std::numeric_limits<char>::max());
        cmd->remoteControlAngles[0] = ClampChar(cmd->remoteControlAngles[0] + static_cast<int>(std::floor(-up * scale * sensitivity)));
        cmd->remoteControlAngles[1] = ClampChar(cmd->remoteControlAngles[1] + static_cast<int>(std::floor(-right * scale * sensitivity)));
    }

    constexpr auto CL_RemoteControlMove = 0x5A6BA0;
    __declspec(naked) void Gamepad::CL_RemoteControlMove_Stub()
    {
        __asm
        {
            // Prepare args for our function call
            push edi // usercmd
            push eax // localClientNum

            call CL_RemoteControlMove

            // Call our function, the args were already prepared earlier
            call CL_RemoteControlMove_GamePad
            add esp, 0x8

            ret
        }
    }

    bool Gamepad::CG_HandleLocationSelectionInput_GamePad(const int localClientNum, Game::usercmd_s* /*cmd*/)
    {
        // Buttons are already handled by keyboard input handler

        const auto frameTime = static_cast<float>(Game::cgArray[0].frametime) * 0.001f;
        const auto mapAspectRatio = Game::cgArray[0].compassMapWorldSize[0] / Game::cgArray[0].compassMapWorldSize[1];
        const auto selectionRequiresAngle = (Game::cgArray[0].predictedPlayerState.locationSelectionInfo & 0x80) != 0;

        auto up = CL_GamepadAxisValue(localClientNum, Game::GPAD_VIRTAXIS_FORWARD);
        auto right = CL_GamepadAxisValue(localClientNum, Game::GPAD_VIRTAXIS_SIDE);
        auto magnitude = up * up + right * right;

        if(magnitude > 1.0f)
        {
            magnitude = std::sqrt(magnitude);
            up /= magnitude;
            right /= magnitude;
        }

        Game::cgArray[0].selectedLocation[0] += right * cg_mapLocationSelectionCursorSpeed.get<float>() * frameTime;
        Game::cgArray[0].selectedLocation[1] -= up * mapAspectRatio * cg_mapLocationSelectionCursorSpeed.get<float>() * frameTime;

        if(selectionRequiresAngle)
        {
            const auto yawUp = CL_GamepadAxisValue(localClientNum, Game::GPAD_VIRTAXIS_PITCH);
            const auto yawRight = CL_GamepadAxisValue(localClientNum, Game::GPAD_VIRTAXIS_YAW);

            if(std::fabs(yawUp) > 0.0f || std::fabs(yawRight) > 0.0f)
            {
                Game::vec2_t vec
                {
                    yawUp,
                    -yawRight
                };

                Game::cgArray[0].selectedLocationAngle = Game::AngleNormalize360(Game::vectoyaw(&vec));
                Game::cgArray[0].selectedAngleLocation[0] = Game::cgArray[0].selectedLocation[0];
                Game::cgArray[0].selectedAngleLocation[1] = Game::cgArray[0].selectedLocation[1];
            }
        }
        else
        {
            Game::cgArray[0].selectedAngleLocation[0] = Game::cgArray[0].selectedLocation[0];
            Game::cgArray[0].selectedAngleLocation[1] = Game::cgArray[0].selectedLocation[1];
        }

        return true;
    }

    constexpr auto CG_HandleLocationSelectionInput = 0x5A67A0;
    __declspec(naked) void Gamepad::CG_HandleLocationSelectionInput_Stub()
    {
        __asm
        {
            // Prepare args for our function call
            push esi // usercmd
            push eax // localClientNum
            
            call CG_HandleLocationSelectionInput

            test al,al
            jz exit_handling

            // Call our function, the args were already prepared earlier
            call CG_HandleLocationSelectionInput_GamePad

        exit_handling:
            add esp, 0x8
            ret
        }
    }

    bool Gamepad::CG_ShouldUpdateViewAngles(const int localClientNum)
    {
        return !Game::Key_IsKeyCatcherActive(localClientNum, Game::KEYCATCH_MASK_ANY) || Game::UI_GetActiveMenu(localClientNum) == Game::UIMENU_SCOREBOARD;
    }

    float Gamepad::CL_GamepadAxisValue(const int gamePadIndex, const Game::GamepadVirtualAxis virtualAxis)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        assert(virtualAxis > Game::GPAD_VIRTAXIS_NONE && virtualAxis < Game::GPAD_VIRTAXIS_COUNT);
        const auto& gamePadGlobal = gamePadGlobals[gamePadIndex];

        const auto& [physicalAxis, mapType] = gamePadGlobal.axes.virtualAxes[virtualAxis];

        if (physicalAxis <= Game::GPAD_PHYSAXIS_NONE || physicalAxis >= Game::GPAD_PHYSAXIS_COUNT)
            return 0.0f;

        auto axisDeflection = gamePadGlobal.axes.axesValues[physicalAxis];

        if (mapType == Game::GPAD_MAP_SQUARED)
        {
            const auto otherAxisSameStick = Game::axisSameStick[physicalAxis];

            float otherAxisDeflection;
            if (otherAxisSameStick <= Game::GPAD_PHYSAXIS_NONE || otherAxisSameStick >= Game::GPAD_PHYSAXIS_COUNT)
                otherAxisDeflection = 0.0f;
            else
                otherAxisDeflection = gamePadGlobal.axes.axesValues[otherAxisSameStick];

            axisDeflection = std::sqrt(axisDeflection * axisDeflection + otherAxisDeflection * otherAxisDeflection) * axisDeflection;
        }

        return axisDeflection;
    }

    char Gamepad::ClampChar(const int value)
    {
        return static_cast<char>(std::clamp<int>(value, std::numeric_limits<char>::min(), std::numeric_limits<char>::max()));
    }

    void Gamepad::CL_GamepadMove(const int gamePadIndex, Game::usercmd_s* cmd, const float frame_time_base)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];
        auto& clientActive = Game::clients[gamePadIndex];

        if (!gpad_enabled.get<bool>() || !gamePad.enabled)
            return;

        auto pitch = CL_GamepadAxisValue(gamePadIndex, Game::GPAD_VIRTAXIS_PITCH);
        if (!input_invertPitch.get<bool>())
            pitch *= -1;

        auto yaw = -CL_GamepadAxisValue(gamePadIndex, Game::GPAD_VIRTAXIS_YAW);
        auto forward = CL_GamepadAxisValue(gamePadIndex, Game::GPAD_VIRTAXIS_FORWARD);
        auto side = CL_GamepadAxisValue(gamePadIndex, Game::GPAD_VIRTAXIS_SIDE);
        //auto attack = CL_GamepadAxisValue(gamePadIndex, Game::GPAD_VIRTAXIS_ATTACK);
        auto moveScale = static_cast<float>(std::numeric_limits<char>::max());

        if (std::fabs(side) > 0.0f || std::fabs(forward) > 0.0f)
        {
            const auto length = std::fabs(side) <= std::fabs(forward)
                                    ? side / forward
                                    : forward / side;
            moveScale = std::sqrt((length * length) + 1.0f) * moveScale;
        }

        const auto forwardMove = static_cast<int>(std::floor(forward * moveScale));
        const auto rightMove = static_cast<int>(std::floor(side * moveScale));

        cmd->rightmove = ClampChar(cmd->rightmove + rightMove);
        cmd->forwardmove = ClampChar(cmd->forwardmove + forwardMove);

        // Check for frozen controls. Flag name should start with PMF_
        if(CG_ShouldUpdateViewAngles(gamePadIndex) && (clientActive.snap.ps.pm_flags & 0x800) == 0)
        {
            Game::AimInput aimInput{};
            Game::AimOutput aimOutput{};
            aimInput.deltaTime = frame_time_base;
            aimInput.buttons = cmd->buttons;
            aimInput.localClientNum = gamePadIndex;
            aimInput.deltaTimeScaled = static_cast<float>(Game::cls->frametime) * 0.001f;
            aimInput.pitch = clientActive.clViewangles[0];
            aimInput.pitchAxis = pitch;
            aimInput.pitchMax = clientActive.cgameMaxPitchSpeed;
            aimInput.yaw = clientActive.clViewangles[1];
            aimInput.yawAxis = yaw;
            aimInput.yawMax = clientActive.cgameMaxYawSpeed;
            aimInput.forwardAxis = forward;
            aimInput.rightAxis = side;
            AimAssist_UpdateGamePadInput(&aimInput, &aimOutput);
            clientActive.clViewangles[0] = aimOutput.pitch;
            clientActive.clViewangles[1] = aimOutput.yaw;
            cmd->meleeChargeDist = aimOutput.meleeChargeDist;
            cmd->meleeChargeYaw = aimOutput.meleeChargeYaw;
        }
    }

    constexpr auto CL_MouseMove = 0x5A6240;

    __declspec(naked) void Gamepad::CL_MouseMove_Stub()
    {
        __asm
        {
            // Prepare args for our function call
            push [esp+0x4] // frametime_base
            push ebx // cmd
            push eax // localClientNum

            push [esp+0x8] // restore frametime_base on the stack
            call CL_MouseMove
            add esp,4

            // Call our function, the args were already prepared earlier
            call CL_GamepadMove
            add esp,0xC

            ret
        }
    }

    bool Gamepad::Key_IsValidGamePadChar(const int key)
    {
        return key >= Game::K_FIRSTGAMEPADBUTTON_RANGE_1 && key <= Game::K_LASTGAMEPADBUTTON_RANGE_1
            || key >= Game::K_FIRSTGAMEPADBUTTON_RANGE_2 && key <= Game::K_LASTGAMEPADBUTTON_RANGE_2
            || key >= Game::K_FIRSTGAMEPADBUTTON_RANGE_3 && key <= Game::K_LASTGAMEPADBUTTON_RANGE_3;
    }

    void Gamepad::CL_GamepadResetMenuScrollTime(const int gamePadIndex, const int key, const bool down, const unsigned time)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePadGlobal = gamePadGlobals[gamePadIndex];

        if (!down)
            return;

        const auto scrollDelayFirst = gpad_menu_scroll_delay_first.get<int>();
        for (const auto scrollButton : Game::menuScrollButtonList)
        {
            if (key == scrollButton)
            {
                gamePadGlobal.nextScrollTime = scrollDelayFirst + time;
                return;
            }
        }
    }

    void Gamepad::CL_GamepadGenerateAPad(const int gamePadIndex, const Game::GamepadPhysicalAxis physicalAxis, unsigned time)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        assert(physicalAxis < Game::GPAD_PHYSAXIS_COUNT && physicalAxis >= 0);

        auto& gamePad = gamePads[gamePadIndex];

        const auto stick = Game::stickForAxis[physicalAxis];
        const auto stickIndex = stick & Game::GPAD_VALUE_MASK;
        if (stick != Game::GPAD_INVALID)
        {
            assert(stickIndex < 4);
            const auto& mapping = Game::analogStickList[stickIndex];

            if (gamePad.stickDown[stickIndex][Game::GPAD_STICK_POS])
            {
                const Game::GamePadButtonEvent event = gamePad.stickDownLast[stickIndex][Game::GPAD_STICK_POS] ? Game::GPAD_BUTTON_UPDATE : Game::GPAD_BUTTON_PRESSED;
                CL_GamepadButtonEvent(gamePadIndex, mapping.posCode, event, time);
            }
            else if (gamePad.stickDown[stickIndex][Game::GPAD_STICK_NEG])
            {
                const Game::GamePadButtonEvent event = gamePad.stickDownLast[stickIndex][Game::GPAD_STICK_NEG] ? Game::GPAD_BUTTON_UPDATE : Game::GPAD_BUTTON_PRESSED;
                CL_GamepadButtonEvent(gamePadIndex, mapping.negCode, event, time);
            }
            else if (gamePad.stickDownLast[stickIndex][Game::GPAD_STICK_POS])
            {
                CL_GamepadButtonEvent(gamePadIndex, mapping.posCode, Game::GPAD_BUTTON_RELEASED, time);
            }
            else if (gamePad.stickDownLast[stickIndex][Game::GPAD_STICK_NEG])
            {
                CL_GamepadButtonEvent(gamePadIndex, mapping.negCode, Game::GPAD_BUTTON_RELEASED, time);
            }
        }
    }

    void Gamepad::CL_GamepadEvent(const int gamePadIndex, const Game::GamepadPhysicalAxis physicalAxis, const float value, const unsigned time)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        assert(physicalAxis < Game::GPAD_PHYSAXIS_COUNT && physicalAxis >= 0);

        auto& gamePad = gamePads[gamePadIndex];
        auto& gamePadGlobal = gamePadGlobals[gamePadIndex];

        gamePadGlobal.axes.axesValues[physicalAxis] = value;
        CL_GamepadGenerateAPad(gamePadIndex, physicalAxis, time);

        if (std::fabs(value) > 0.0f)
        {
            gamePad.inUse = true;
            gpad_in_use.setRaw(true);
        }
    }

    void Gamepad::UI_GamepadKeyEvent(const int gamePadIndex, const int key, const bool down)
    {
        for (const auto& mapping : controllerMenuKeyMappings)
        {
            if (mapping.controllerKey == key)
            {
                Game::UI_KeyEvent(gamePadIndex, mapping.pcKey, down);
                return;
            }
        }

        // No point in sending unmapped controller keystrokes to the key event handler since it doesn't know how to use it anyway
        // Game::UI_KeyEvent(gamePadIndex, key, down);
    }

    bool Gamepad::CL_CheckForIgnoreDueToRepeat(const int gamePadIndex, const int key, const int repeatCount, const unsigned time)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePadGlobal = gamePadGlobals[gamePadIndex];

        if (Game::Key_IsKeyCatcherActive(gamePadIndex, Game::KEYCATCH_UI))
        {
            const int scrollDelayFirst = gpad_menu_scroll_delay_first.get<int>();
            const int scrollDelayRest = gpad_menu_scroll_delay_rest.get<int>();

            for (const auto menuScrollButton : Game::menuScrollButtonList)
            {
                if (key == menuScrollButton)
                {
                    if (repeatCount == 1)
                    {
                        gamePadGlobal.nextScrollTime = time + scrollDelayFirst;
                        return false;
                    }

                    if (time > gamePadGlobal.nextScrollTime)
                    {
                        gamePadGlobal.nextScrollTime = time + scrollDelayRest;
                        return false;
                    }
                    break;
                }
            }
        }

        return repeatCount > 1;
    }

    void Gamepad::CL_GamepadButtonEvent(const int gamePadIndex, const int key, const Game::GamePadButtonEvent buttonEvent, const unsigned time)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);

        const auto pressed = buttonEvent == Game::GPAD_BUTTON_PRESSED;
        const auto pressedOrUpdated = pressed || buttonEvent == Game::GPAD_BUTTON_UPDATE;

        auto& keyState = Game::playerKeys[gamePadIndex];
        keyState.keys[key].down = pressedOrUpdated;

        if (pressedOrUpdated)
        {
            if (++keyState.keys[key].repeats == 1)
                keyState.anyKeyDown++;
        }
        else if (buttonEvent == Game::GPAD_BUTTON_RELEASED && keyState.keys[key].repeats > 0)
        {
            keyState.keys[key].repeats = 0;
            if (--keyState.anyKeyDown < 0)
                keyState.anyKeyDown = 0;
        }

        if (pressedOrUpdated && CL_CheckForIgnoreDueToRepeat(gamePadIndex, key, keyState.keys[key].repeats, time))
            return;

        if (Game::Key_IsKeyCatcherActive(gamePadIndex, Game::KEYCATCH_LOCATION_SELECTION) && pressedOrUpdated)
        {
            if (key == Game::K_BUTTON_B || keyState.keys[key].binding && strcmp(keyState.keys[key].binding, "+actionslot 4") == 0)
            {
                keyState.locSelInputState = Game::LOC_SEL_INPUT_CANCEL;
            }
            else if (key == Game::K_BUTTON_A || keyState.keys[key].binding && strcmp(keyState.keys[key].binding, "+attack") == 0)
            {
                keyState.locSelInputState = Game::LOC_SEL_INPUT_CONFIRM;
            }
            return;
        }

        keyState.locSelInputState = Game::LOC_SEL_INPUT_NONE;

        const auto* keyBinding = keyState.keys[key].binding;

        char cmd[1024];
        if (pressedOrUpdated)
        {
            if (Game::Key_IsKeyCatcherActive(gamePadIndex, Game::KEYCATCH_UI))
            {
                UI_GamepadKeyEvent(gamePadIndex, key, pressedOrUpdated);
                return;
            }

            if (keyBinding)
            {
                if (keyBinding[0] == '+')
                {
                    sprintf_s(cmd, "%s %i %i\n", keyBinding, key, time);
                    Game::Cbuf_AddText(gamePadIndex, cmd);
                }
                else
                {
                    Game::Cbuf_AddText(gamePadIndex, keyBinding);
                    Game::Cbuf_AddText(gamePadIndex, "\n");
                }
            }
        }
        else
        {
            if (keyBinding && keyBinding[0] == '+')
            {
                sprintf_s(cmd, "-%s %i %i\n", &keyBinding[1], key, time);
                Game::Cbuf_AddText(gamePadIndex, cmd);
            }

            if (Game::Key_IsKeyCatcherActive(gamePadIndex, Game::KEYCATCH_UI))
            {
                UI_GamepadKeyEvent(gamePadIndex, key, pressedOrUpdated);
            }
        }
    }

    void Gamepad::CL_GamepadButtonEventForPort(const int gamePadIndex, const int key, const Game::GamePadButtonEvent buttonEvent, const unsigned time)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        gamePad.inUse = true;
        gpad_in_use.setRaw(true);

        if (Game::Key_IsKeyCatcherActive(gamePadIndex, Game::KEYCATCH_UI))
            CL_GamepadResetMenuScrollTime(gamePadIndex, key, buttonEvent == Game::GPAD_BUTTON_PRESSED, time);


        CL_GamepadButtonEvent(gamePadIndex, key, buttonEvent, time);
    }

    void Gamepad::GPad_ConvertStickToFloat(const short x, const short y, float& outX, float& outY)
    {
        Game::vec2_t stickVec;
        stickVec[0] = static_cast<float>(x) / static_cast<float>(std::numeric_limits<short>::max());
        stickVec[1] = static_cast<float>(y) / static_cast<float>(std::numeric_limits<short>::max());

        const auto deadZoneTotal = gpad_stick_deadzone_min.get<float>() + gpad_stick_deadzone_max.get<float>();
        auto len = Game::Vec2Normalize(stickVec);

        if (gpad_stick_deadzone_min.get<float>() <= len)
        {
            if (1.0f - gpad_stick_deadzone_max.get<float>() >= len)
                len = (len - gpad_stick_deadzone_min.get<float>()) / (1.0f - deadZoneTotal);
            else
                len = 1.0f;
        }
        else
            len = 0.0f;

        outX = stickVec[0] * len;
        outY = stickVec[1] * len;
    }

    float Gamepad::GPad_GetStick(const int gamePadIndex, const Game::GamePadStick stick)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        return gamePad.sticks[stick];
    }

    float Gamepad::GPad_GetButton(const int gamePadIndex, Game::GamePadButton button)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        float value = 0.0f;

        if (button & Game::GPAD_DIGITAL_MASK)
        {
            const auto buttonValue = button & Game::GPAD_VALUE_MASK;
            value = buttonValue & gamePad.digitals ? 1.0f : 0.0f;
        }
        else if (button & Game::GPAD_ANALOG_MASK)
        {
            const auto analogIndex = button & Game::GPAD_VALUE_MASK;
            if (analogIndex < std::extent_v<decltype(gamePad.analogs)>)
            {
                value = gamePad.analogs[analogIndex];
            }
        }

        return value;
    }

    bool Gamepad::GPad_IsButtonPressed(const int gamePadIndex, Game::GamePadButton button)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        bool down = false;
        bool lastDown = false;

        if (button & Game::GPAD_DIGITAL_MASK)
        {
            const auto buttonValue = button & Game::GPAD_VALUE_MASK;
            down = (buttonValue & gamePad.digitals) != 0;
            lastDown = (buttonValue & gamePad.lastDigitals) != 0;
        }
        else if (button & Game::GPAD_ANALOG_MASK)
        {
            const auto analogIndex = button & Game::GPAD_VALUE_MASK;
            assert(analogIndex < std::extent_v<decltype(gamePad.analogs)>);

            if (analogIndex < std::extent_v<decltype(gamePad.analogs)>)
            {
                down = gamePad.analogs[analogIndex] > 0.0f;
                lastDown = gamePad.lastAnalogs[analogIndex] > 0.0f;
            }
        }

        return down && !lastDown;
    }

    bool Gamepad::GPad_ButtonRequiresUpdates(const int gamePadIndex, Game::GamePadButton button)
    {
        return (button & Game::GPAD_ANALOG_MASK || button & Game::GPAD_DPAD_MASK) && GPad_GetButton(gamePadIndex, button) > 0.0f;
    }

    bool Gamepad::GPad_IsButtonReleased(int gamePadIndex, Game::GamePadButton button)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        bool down = false;
        bool lastDown = false;

        if (button & Game::GPAD_DIGITAL_MASK)
        {
            const auto buttonValue = button & Game::GPAD_VALUE_MASK;

            down = (gamePad.digitals & buttonValue) != 0;
            lastDown = (gamePad.lastDigitals & buttonValue) != 0;
        }
        else if (button & Game::GPAD_ANALOG_MASK)
        {
            const auto analogIndex = button & Game::GPAD_VALUE_MASK;
            assert(analogIndex < std::extent_v<decltype(gamePad.analogs)>);

            if (analogIndex < std::extent_v<decltype(gamePad.analogs)>)
            {
                down = gamePad.analogs[analogIndex] > 0.0f;
                lastDown = gamePad.lastAnalogs[analogIndex] > 0.0f;
            }
        }

        return !down && lastDown;
    }

    void Gamepad::GPad_UpdateSticksDown(const int gamePadIndex)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePad = gamePads[gamePadIndex];

        for (auto stickIndex = 0u; stickIndex < std::extent_v<decltype(GamePad::sticks)>; stickIndex++)
        {
            for (auto dir = 0; dir < Game::GPAD_STICK_DIR_COUNT; dir++)
            {
                gamePad.stickDownLast[stickIndex][dir] = gamePad.stickDown[stickIndex][dir];

                auto threshold = gpad_stick_pressed.get<float>();

                if (gamePad.stickDownLast[stickIndex][dir])
                    threshold -= gpad_stick_pressed_hysteresis.get<float>();
                else
                    threshold += gpad_stick_pressed_hysteresis.get<float>();

                if (dir == Game::GPAD_STICK_POS)
                {
                    gamePad.stickDown[stickIndex][dir] = gamePad.sticks[stickIndex] > threshold;
                }
                else
                {
                    assert(dir == Game::GPAD_STICK_NEG);
                    gamePad.stickDown[stickIndex][dir] = gamePad.sticks[stickIndex] < -threshold;
                }
            }
        }
    }

    void Gamepad::GPad_UpdateSticks(const int gamePadIndex, const XINPUT_GAMEPAD& state)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);

        auto& gamePad = gamePads[gamePadIndex];

        Game::vec2_t lVec, rVec;
        GPad_ConvertStickToFloat(state.sThumbLX, state.sThumbLY, lVec[0], lVec[1]);
        GPad_ConvertStickToFloat(state.sThumbRX, state.sThumbRY, rVec[0], rVec[1]);

        gamePad.lastSticks[0] = gamePad.sticks[0];
        gamePad.sticks[0] = lVec[0];
        gamePad.lastSticks[1] = gamePad.sticks[1];
        gamePad.sticks[1] = lVec[1];
        gamePad.lastSticks[2] = gamePad.sticks[2];
        gamePad.sticks[2] = rVec[0];
        gamePad.lastSticks[3] = gamePad.sticks[3];
        gamePad.sticks[3] = rVec[1];

        GPad_UpdateSticksDown(gamePadIndex);

#ifdef DEBUG
        if (gpad_debug.get<bool>())
        {
            Logger::Print("Left: X: %f Y: %f\n", lVec[0], lVec[1]);
            Logger::Print("Right: X: %f Y: %f\n", rVec[0], rVec[1]);
            Logger::Print("Down: %i:%i %i:%i %i:%i %i:%i\n", gamePad.stickDown[0][Game::GPAD_STICK_POS], gamePad.stickDown[0][Game::GPAD_STICK_NEG],
                          gamePad.stickDown[1][Game::GPAD_STICK_POS], gamePad.stickDown[1][Game::GPAD_STICK_NEG],
                          gamePad.stickDown[2][Game::GPAD_STICK_POS], gamePad.stickDown[2][Game::GPAD_STICK_NEG],
                          gamePad.stickDown[3][Game::GPAD_STICK_POS], gamePad.stickDown[3][Game::GPAD_STICK_NEG]);
        }
#endif
    }

    void Gamepad::GPad_UpdateDigitals(const int gamePadIndex, const XINPUT_GAMEPAD& state)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);

        auto& gamePad = gamePads[gamePadIndex];

        gamePad.lastDigitals = gamePad.digitals;
        gamePad.digitals = state.wButtons;

        const auto leftDeflect = gpad_button_lstick_deflect_max.get<float>();
        if (std::fabs(gamePad.sticks[0]) > leftDeflect || std::fabs(gamePad.sticks[1]) > leftDeflect)
            gamePad.digitals &= ~static_cast<short>(XINPUT_GAMEPAD_LEFT_THUMB);
        const auto rightDeflect = gpad_button_rstick_deflect_max.get<float>();
        if (std::fabs(gamePad.sticks[2]) > leftDeflect || std::fabs(gamePad.sticks[3]) > rightDeflect)
            gamePad.digitals &= ~static_cast<short>(XINPUT_GAMEPAD_RIGHT_THUMB);

#ifdef DEBUG
        if (gpad_debug.get<bool>())
        {
            Logger::Print("Buttons: %x\n", gamePad.digitals);
        }
#endif
    }

    void Gamepad::GPad_UpdateAnalogs(const int gamePadIndex, const XINPUT_GAMEPAD& state)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);

        auto& gamePad = gamePads[gamePadIndex];

        const auto buttonDeadZone = gpad_button_deadzone.get<float>();

        gamePad.lastAnalogs[0] = gamePad.analogs[0];
        gamePad.analogs[0] = static_cast<float>(state.bLeftTrigger) / static_cast<float>(std::numeric_limits<unsigned char>::max());
        if (gamePad.analogs[0] < buttonDeadZone)
            gamePad.analogs[0] = 0.0f;


        gamePad.lastAnalogs[1] = gamePad.analogs[1];
        gamePad.analogs[1] = static_cast<float>(state.bRightTrigger) / static_cast<float>(std::numeric_limits<unsigned char>::max());
        if (gamePad.analogs[1] < buttonDeadZone)
            gamePad.analogs[1] = 0.0f;

#ifdef DEBUG
        if (gpad_debug.get<bool>())
        {
            Logger::Print("Triggers: %f %f\n", gamePad.analogs[0], gamePad.analogs[1]);
        }
#endif
    }

    void Gamepad::GPad_UpdateAll()
    {
        GPad_RefreshAll();

        for (auto currentGamePadIndex = 0; currentGamePadIndex < Game::MAX_GAMEPADS; currentGamePadIndex++)
        {
            const auto& gamePad = gamePads[currentGamePadIndex];
            if (!gamePad.enabled)
                continue;

            XINPUT_STATE inputState;
            if (XInputGetState(gamePad.portIndex, &inputState) != ERROR_SUCCESS)
                continue;

            GPad_UpdateSticks(currentGamePadIndex, inputState.Gamepad);
            GPad_UpdateDigitals(currentGamePadIndex, inputState.Gamepad);
            GPad_UpdateAnalogs(currentGamePadIndex, inputState.Gamepad);
        }
    }

    void Gamepad::IN_GamePadsMove()
    {
        GPad_UpdateAll();
        const auto time = Game::Sys_Milliseconds();

        bool gpadPresent = false;
        for (auto gamePadIndex = 0; gamePadIndex < Game::MAX_GAMEPADS; gamePadIndex++)
        {
            const auto& gamePad = gamePads[gamePadIndex];

            if (gamePad.enabled)
            {
                gpadPresent = true;
                const auto lx = GPad_GetStick(gamePadIndex, Game::GPAD_LX);
                const auto ly = GPad_GetStick(gamePadIndex, Game::GPAD_LY);
                const auto rx = GPad_GetStick(gamePadIndex, Game::GPAD_RX);
                const auto ry = GPad_GetStick(gamePadIndex, Game::GPAD_RY);
                const auto leftTrig = GPad_GetButton(gamePadIndex, Game::GPAD_L_TRIG);
                const auto rightTrig = GPad_GetButton(gamePadIndex, Game::GPAD_R_TRIG);

                CL_GamepadEvent(gamePadIndex, Game::GPAD_PHYSAXIS_LSTICK_X, lx, time);
                CL_GamepadEvent(gamePadIndex, Game::GPAD_PHYSAXIS_LSTICK_Y, ly, time);
                CL_GamepadEvent(gamePadIndex, Game::GPAD_PHYSAXIS_RSTICK_X, rx, time);
                CL_GamepadEvent(gamePadIndex, Game::GPAD_PHYSAXIS_RSTICK_Y, ry, time);
                CL_GamepadEvent(gamePadIndex, Game::GPAD_PHYSAXIS_LTRIGGER, leftTrig, time);
                CL_GamepadEvent(gamePadIndex, Game::GPAD_PHYSAXIS_RTRIGGER, rightTrig, time);

                for (const auto& buttonMapping : Game::buttonList)
                {
                    if (GPad_IsButtonPressed(gamePadIndex, buttonMapping.padButton))
                    {
                        CL_GamepadButtonEventForPort(
                            gamePadIndex,
                            buttonMapping.code,
                            Game::GPAD_BUTTON_PRESSED,
                            time);
                    }
                    else if (GPad_ButtonRequiresUpdates(gamePadIndex, buttonMapping.padButton))
                    {
                        CL_GamepadButtonEventForPort(
                            gamePadIndex,
                            buttonMapping.code,
                            Game::GPAD_BUTTON_UPDATE,
                            time);
                    }
                    else if (GPad_IsButtonReleased(gamePadIndex, buttonMapping.padButton))
                    {
                        CL_GamepadButtonEventForPort(
                            gamePadIndex,
                            buttonMapping.code,
                            Game::GPAD_BUTTON_RELEASED,
                            time);
                    }
                }
            }
        }

        gpad_present.setRaw(gpadPresent);
    }


    void Gamepad::IN_Frame_Hk()
    {
        // Call original method
        Utils::Hook::Call<void()>(0x64C490)();

        IN_GamePadsMove();
    }

    void Gamepad::Gamepad_WriteBindings(const int gamePadIndex, const int handle)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        auto& gamePadGlobal = gamePadGlobals[gamePadIndex];

        Game::FS_Printf(handle, "unbindallaxis\n");

        for (auto virtualAxisIndex = 0u; virtualAxisIndex < Game::GPAD_VIRTAXIS_COUNT; virtualAxisIndex++)
        {
            const auto& axisMapping = gamePadGlobal.axes.virtualAxes[virtualAxisIndex];
            if (axisMapping.physicalAxis <= Game::GPAD_PHYSAXIS_NONE || axisMapping.physicalAxis >= Game::GPAD_PHYSAXIS_COUNT
                || axisMapping.mapType <= Game::GPAD_MAP_NONE || axisMapping.mapType >= Game::GPAD_MAP_COUNT)
            {
                continue;
            }

            const auto* physicalAxisName = Game::physicalAxisNames[axisMapping.physicalAxis];
            const auto* virtualAxisName = Game::virtualAxisNames[virtualAxisIndex];
            const auto* mappingName = Game::gamePadMappingTypeNames[axisMapping.mapType];

            Game::FS_Printf(handle, "bindaxis %s %s %s\n", physicalAxisName, virtualAxisName, mappingName);
        }
    }

    void Gamepad::Key_WriteBindings_Hk(const int localClientNum, const int handle)
    {
        // Call original function
        Utils::Hook::Call<void(int, int)>(0x4A5A20)(localClientNum, handle);

        Gamepad_WriteBindings(0, handle);
    }

    void __declspec(naked) Gamepad::Com_WriteConfiguration_Modified_Stub()
    {
        __asm
        {
            mov eax, [ecx + 0x18]
            or eax, gamePadBindingsModifiedFlags // Also check for gamePadBindingsModifiedFlags
            test al, 1
            jz endMethod
            mov gamePadBindingsModifiedFlags, 0 // Reset gamePadBindingsModifiedFlags
            mov eax, [ecx + 0x18] // Restore eax to dvar_modified_flags

            push 0x60B26E
            retn

            endMethod:
            push 0x60B298
            retn
        }
    }


    void Gamepad::Gamepad_BindAxis(const int gamePadIndex, const Game::GamepadPhysicalAxis realIndex, const Game::GamepadVirtualAxis axisIndex, const Game::GamepadMapping mapType)
    {
        assert(gamePadIndex < Game::MAX_GAMEPADS);
        assert(realIndex > Game::GPAD_PHYSAXIS_NONE && realIndex < Game::GPAD_PHYSAXIS_COUNT);
        assert(axisIndex > Game::GPAD_VIRTAXIS_NONE && axisIndex < Game::GPAD_VIRTAXIS_COUNT);
        assert(mapType > Game::GPAD_MAP_NONE && mapType < Game::GPAD_MAP_COUNT);

        auto& gamePadGlobal = gamePadGlobals[gamePadIndex];
        gamePadGlobal.axes.virtualAxes[axisIndex].physicalAxis = realIndex;
        gamePadGlobal.axes.virtualAxes[axisIndex].mapType = mapType;

        gamePadBindingsModifiedFlags |= 1;
    }

    Game::GamepadPhysicalAxis Gamepad::StringToPhysicalAxis(const char* str)
    {
        for (auto i = 0u; i < std::extent_v<decltype(Game::physicalAxisNames)>; i++)
        {
            if (strcmp(str, Game::physicalAxisNames[i]) == 0)
                return static_cast<Game::GamepadPhysicalAxis>(i);
        }

        return Game::GPAD_PHYSAXIS_NONE;
    }

    Game::GamepadVirtualAxis Gamepad::StringToVirtualAxis(const char* str)
    {
        for (auto i = 0u; i < std::extent_v<decltype(Game::virtualAxisNames)>; i++)
        {
            if (strcmp(str, Game::virtualAxisNames[i]) == 0)
                return static_cast<Game::GamepadVirtualAxis>(i);
        }

        return Game::GPAD_VIRTAXIS_NONE;
    }

    Game::GamepadMapping Gamepad::StringToGamePadMapping(const char* str)
    {
        for (auto i = 0u; i < std::extent_v<decltype(Game::gamePadMappingTypeNames)>; i++)
        {
            if (strcmp(str, Game::gamePadMappingTypeNames[i]) == 0)
                return static_cast<Game::GamepadMapping>(i);
        }

        return Game::GPAD_MAP_NONE;
    }

    void Gamepad::Axis_Bind_f(Command::Params* params)
    {
        if (params->length() < 4)
        {
            Logger::Print("bindaxis <real axis> <virtual axis> <input type>\n");
            return;
        }

        const auto* physicalAxisText = params->get(1);
        const auto* virtualAxisText = params->get(2);
        const auto* mappingText = params->get(3);

        const Game::GamepadPhysicalAxis physicalAxis = StringToPhysicalAxis(physicalAxisText);
        if (physicalAxis == Game::GPAD_PHYSAXIS_NONE)
        {
            Logger::Print("\"%s\" isn't a valid physical axis\n", physicalAxisText);
            return;
        }

        const Game::GamepadVirtualAxis virtualAxis = StringToVirtualAxis(virtualAxisText);
        if (virtualAxis == Game::GPAD_VIRTAXIS_NONE)
        {
            Logger::Print("\"%s\" isn't a valid virtual axis\n", virtualAxisText);
            return;
        }

        const Game::GamepadMapping mapping = StringToGamePadMapping(mappingText);
        if (mapping == Game::GPAD_MAP_NONE)
        {
            Logger::Print("\"%s\" isn't a valid input type\n", mappingText);
            return;
        }

        Gamepad_BindAxis(0, physicalAxis, virtualAxis, mapping);
    }

    void Gamepad::Axis_Unbindall_f(Command::Params*)
    {
        auto& gamePadGlobal = gamePadGlobals[0];

        for (auto& virtualAxis : gamePadGlobal.axes.virtualAxes)
        {
            virtualAxis.physicalAxis = Game::GPAD_PHYSAXIS_NONE;
            virtualAxis.mapType = Game::GPAD_MAP_NONE;
        }
    }

    void Gamepad::Bind_GP_SticksConfigs_f(Command::Params*)
    {
        const auto* stickConfigName = gpad_sticksConfig.get<const char*>();
        Game::Cbuf_AddText(0, Utils::String::VA("exec %s\n", stickConfigName));
    }

    void Gamepad::Bind_GP_ButtonsConfigs_f(Command::Params*)
    {
        const auto* buttonConfigName = gpad_buttonConfig.get<const char*>();
        Game::Cbuf_AddText(0, Utils::String::VA("exec %s\n", buttonConfigName));
    }

    void Gamepad::InitDvars()
    {
        gpad_enabled = Dvar::Register<bool>("gpad_enabled", false, Game::DVAR_FLAG_SAVED, "Game pad enabled");
        gpad_debug = Dvar::Register<bool>("gpad_debug", false, 0, "Game pad debugging");
        gpad_present = Dvar::Register<bool>("gpad_present", false, 0, "Game pad present");
        gpad_in_use = Dvar::Register<bool>("gpad_in_use", false, 0, "A game pad is in use");
        gpad_sticksConfig = Dvar::Register<const char*>("gpad_sticksConfig", "thumbstick_default", Game::DVAR_FLAG_SAVED, "Game pad stick configuration");
        gpad_buttonConfig = Dvar::Register<const char*>("gpad_buttonConfig", "buttons_default", Game::DVAR_FLAG_SAVED, "Game pad button configuration");
        gpad_menu_scroll_delay_first = Dvar::Register<int>("gpad_menu_scroll_delay_first", 420, 0, 1000, Game::DVAR_FLAG_SAVED, "Menu scroll key-repeat delay, for the first repeat, in milliseconds");
        gpad_menu_scroll_delay_rest = Dvar::Register<int>("gpad_menu_scroll_delay_rest", 210, 0, 1000, Game::DVAR_FLAG_SAVED,
                                                          "Menu scroll key-repeat delay, for repeats after the first, in milliseconds");
        gpad_rumble = Dvar::Register<bool>("gpad_rumble", true, Game::DVAR_FLAG_SAVED, "Enable game pad rumble");
        gpad_stick_pressed_hysteresis = Dvar::Register<float>("gpad_stick_pressed_hysteresis", 0.1f, 0.0f, 1.0f, 0,
                                                              "Game pad stick pressed no-change-zone around gpad_stick_pressed to prevent bouncing");
        gpad_stick_pressed = Dvar::Register<float>("gpad_stick_pressed", 0.4f, 0.0, 1.0, 0, "Game pad stick pressed threshhold");
        gpad_stick_deadzone_max = Dvar::Register<float>("gpad_stick_deadzone_max", 0.01f, 0.0f, 1.0f, 0, "Game pad maximum stick deadzone");
        gpad_stick_deadzone_min = Dvar::Register<float>("gpad_stick_deadzone_min", 0.2f, 0.0f, 1.0f, 0, "Game pad minimum stick deadzone");
        gpad_button_deadzone = Dvar::Register<float>("gpad_button_deadzone", 0.13f, 0.0f, 1.0f, 0, "Game pad button deadzone threshhold");
        gpad_button_lstick_deflect_max = Dvar::Register<float>("gpad_button_lstick_deflect_max", 1.0f, 0.0f, 1.0f, 0, "Game pad maximum pad stick pressed value");
        gpad_button_rstick_deflect_max = Dvar::Register<float>("gpad_button_rstick_deflect_max", 1.0f, 0.0f, 1.0f, 0, "Game pad maximum pad stick pressed value");

        input_viewSensitivity = Dvar::Register<float>("input_viewSensitivity", 1.0f, 0.0001f, 5.0f, Game::DVAR_FLAG_SAVED, "View Sensitivity");
        input_invertPitch = Dvar::Register<bool>("input_invertPitch", false, Game::DVAR_FLAG_SAVED, "Invert gamepad pitch");
        aim_turnrate_pitch = Dvar::Var("aim_turnrate_pitch");
        aim_turnrate_pitch_ads = Dvar::Var("aim_turnrate_pitch_ads");
        aim_turnrate_yaw = Dvar::Var("aim_turnrate_yaw");
        aim_turnrate_yaw_ads = Dvar::Var("aim_turnrate_yaw_ads");
        aim_accel_turnrate_enabled = Dvar::Var("aim_accel_turnrate_enabled");
        aim_accel_turnrate_lerp = Dvar::Var("aim_accel_turnrate_lerp");
        aim_input_graph_enabled = Dvar::Var("aim_input_graph_enabled");
        aim_input_graph_index = Dvar::Var("aim_input_graph_index");
        aim_scale_view_axis = Dvar::Var("aim_scale_view_axis");
        cl_bypassMouseInput = Dvar::Var("cl_bypassMouseInput");
        cg_mapLocationSelectionCursorSpeed = Dvar::Var("cg_mapLocationSelectionCursorSpeed");
    }

    void Gamepad::IN_Init_Hk()
    {
        // Call original method
        Utils::Hook::Call<void()>(0x45D620)();

        InitDvars();
    }

    const char* Gamepad::GetGamePadCommand(const char* command)
    {
        if (strcmp(command, "+activate") == 0 || strcmp(command, "+reload") == 0)
            return "+usereload";
        if (strcmp(command, "+melee_breath") == 0)
            return "+holdbreath";

        return command;
    }

    int Gamepad::Key_GetCommandAssignmentInternal_Hk(const char* cmd, int (*keys)[2])
    {
        auto keyCount = 0;

        if (gamePads[0].inUse)
        {
            cmd = GetGamePadCommand(cmd);
            for (auto keyNum = 0; keyNum < Game::K_LAST_KEY; keyNum++)
            {
                if (!Key_IsValidGamePadChar(keyNum))
                    continue;

                if (Game::playerKeys[0].keys[keyNum].binding && strcmp(Game::playerKeys[0].keys[keyNum].binding, cmd) == 0)
                {
                    (*keys)[keyCount++] = keyNum;

                    if (keyCount >= 2)
                        return keyNum;
                }
            }
        }
        else
        {
            for (auto keyNum = 0; keyNum < Game::K_LAST_KEY; keyNum++)
            {
                if (Key_IsValidGamePadChar(keyNum))
                    continue;

                if (Game::playerKeys[0].keys[keyNum].binding && strcmp(Game::playerKeys[0].keys[keyNum].binding, cmd) == 0)
                {
                    (*keys)[keyCount++] = keyNum;

                    if (keyCount >= 2)
                        return keyNum;
                }
            }
        }

        return keyCount;
    }

    void Gamepad::CL_KeyEvent_Hk(const int localClientNum, const int key, const int down, const unsigned time)
    {
        // A keyboard key has been pressed. Mark controller as unused.
        gamePads[0].inUse = false;
        gpad_in_use.setRaw(false);

        // Call original function
        Utils::Hook::Call<void(int, int, int, unsigned)>(0x4F6480)(localClientNum, key, down, time);
    }

    bool Gamepad::IsGamePadInUse()
    {
        return gamePads[0].inUse;
    }

    int Gamepad::CL_MouseEvent_Hk(const int x, const int y, const int dx, const int dy)
    {
        if(dx != 0 || dy != 0)
        {
            gamePads[0].inUse = false;
            gpad_in_use.setRaw(false);
        }

        // Call original function
        return Utils::Hook::Call<int(int, int, int, int)>(0x4D7C50)(x, y, dx, dy);
    }

    bool Gamepad::UI_RefreshViewport_Hk()
    {
        return cl_bypassMouseInput.get<bool>() || IsGamePadInUse();
    }

    void Gamepad::CreateKeyNameMap()
    {
        memcpy(Game::combinedKeyNames, Game::vanillaKeyNames, sizeof(Game::keyname_t) * Game::VANILLA_KEY_NAME_COUNT);
        memcpy(&Game::combinedKeyNames[Game::VANILLA_KEY_NAME_COUNT], Game::extendedKeyNames, sizeof(Game::keyname_t) * std::extent_v<decltype(Game::extendedKeyNames)>);
        Game::combinedKeyNames[std::extent_v<decltype(Game::combinedKeyNames)> - 1] = {nullptr, 0};

        memcpy(Game::combinedLocalizedKeyNames, Game::vanillaLocalizedKeyNames, sizeof(Game::keyname_t) * Game::VANILLA_LOCALIZED_KEY_NAME_COUNT);
        memcpy(&Game::combinedLocalizedKeyNames[Game::VANILLA_LOCALIZED_KEY_NAME_COUNT], Game::extendedLocalizedKeyNames,
               sizeof(Game::keyname_t) * std::extent_v<decltype(Game::extendedLocalizedKeyNames)>);
        Game::combinedLocalizedKeyNames[std::extent_v<decltype(Game::combinedLocalizedKeyNames)> - 1] = {nullptr, 0};

        Utils::Hook::Set<Game::keyname_t*>(0x4A780A, Game::combinedKeyNames);
        Utils::Hook::Set<Game::keyname_t*>(0x4A7810, Game::combinedKeyNames);
        Utils::Hook::Set<Game::keyname_t*>(0x435C9F, Game::combinedKeyNames);
        Utils::Hook::Set<Game::keyname_t*>(0x435C98, Game::combinedLocalizedKeyNames);
    }

    Gamepad::Gamepad()
    {
        if (ZoneBuilder::IsEnabled())
            return;

        // package the forward and right move components in the move buttons
        Utils::Hook(0x60E38D, MSG_WriteDeltaUsercmdKeyStub, HOOK_JUMP).install()->quick();

        // send two bytes for sending movement data
        Utils::Hook::Set<BYTE>(0x60E501, 16);
        Utils::Hook::Set<BYTE>(0x60E5CD, 16);

        // make sure to parse the movement data properly and apply it
        Utils::Hook(0x492127, MSG_ReadDeltaUsercmdKeyStub, HOOK_JUMP).install()->quick();
        Utils::Hook(0x492009, MSG_ReadDeltaUsercmdKeyStub2, HOOK_JUMP).install()->quick();

        // Also rewrite configuration when gamepad config is dirty
        Utils::Hook(0x60B264, Com_WriteConfiguration_Modified_Stub, HOOK_JUMP).install()->quick();
        Utils::Hook(0x60B223, Key_WriteBindings_Hk, HOOK_CALL).install()->quick();

        CreateKeyNameMap();

        Command::Add("bindaxis", Axis_Bind_f);
        Command::Add("unbindallaxis", Axis_Unbindall_f);
        Command::Add("bindgpsticksconfigs", Bind_GP_SticksConfigs_f);
        Command::Add("bindgpbuttonsconfigs", Bind_GP_ButtonsConfigs_f);

        if (Dedicated::IsEnabled())
            return;

        // Initialize gamepad environment
        Utils::Hook(0x467C03, IN_Init_Hk, HOOK_CALL).install()->quick();

        // Gamepad on frame hook
        Utils::Hook(0x475E9E, IN_Frame_Hk, HOOK_CALL).install()->quick();

        // Mark controller as unused when keyboard key is pressed
        Utils::Hook(0x43D179, CL_KeyEvent_Hk, HOOK_CALL).install()->quick();

        // Mark controller as unused when mouse is moved
        Utils::Hook(0x64C507, CL_MouseEvent_Hk, HOOK_CALL).install()->quick(); 

        // Hide cursor when controller is active
        Utils::Hook(0x48E527, UI_RefreshViewport_Hk, HOOK_CALL).install()->quick();

        // Only return gamepad keys when gamepad enabled and only non gamepad keys when not
        Utils::Hook(0x5A7A23, Key_GetCommandAssignmentInternal_Hk, HOOK_CALL).install()->quick();

        // Add gamepad inputs to remote control (eg predator) handling
        Utils::Hook(0x5A6D4E, CL_RemoteControlMove_Stub, HOOK_CALL).install()->quick();

        // Add gamepad inputs to location selection (eg airstrike location) handling
        Utils::Hook(0x5A6D72, CG_HandleLocationSelectionInput_Stub, HOOK_CALL).install()->quick();

        // Add gamepad inputs to usercmds
        Utils::Hook(0x5A6DAE, CL_MouseMove_Stub, HOOK_CALL).install()->quick();
    }
}
