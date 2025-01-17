/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Implementation of the GameEngine interface.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "win32gameengine.h"
#include "main.h"
#include "w3dfunctionlexicon.h"
#include "w3dmodulefactory.h"
#include "win32bigfilesystem.h"
#include "win32localfilesystem.h"

#ifdef BUILD_WITH_MILES
#include "milesaudiomanager.h"
#endif

#ifdef PLATFORM_WINDOWS
#include <winuser.h>
#endif

#ifdef BUILD_WITH_STDFS
#include "stdlocalfilesystem.h"
#endif

Win32GameEngine::Win32GameEngine()
{
#ifdef PLATFORM_WINDOWS
    m_previousErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS);
#endif
}

Win32GameEngine::~Win32GameEngine()
{
#ifdef PLATFORM_WINDOWS
    SetErrorMode(m_previousErrorMode);
#endif
}

void Win32GameEngine::Service_Windows_OS()
{
// Event loop.
#ifdef PLATFORM_WINDOWS
    BOOL result;
    MSG Msg;

    for (result = PeekMessageA(&Msg, 0, 0, 0, 0); result; result = PeekMessageA(&Msg, 0, 0, 0, 0)) {
        GetMessageA(&Msg, 0, 0, 0);
        g_theMessageTime = Msg.time;
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
        g_theMessageTime = 0;
    }
#endif
}

LocalFileSystem *Win32GameEngine::Create_Local_File_System()
{
#ifdef BUILD_WITH_STDFS
    return new Thyme::StdLocalFileSystem;
#else
    return new Win32LocalFileSystem;
#endif
}

ArchiveFileSystem *Win32GameEngine::Create_Archive_File_System()
{
    return new Win32BIGFileSystem;
}

GameLogic *Win32GameEngine::Create_Game_Logic()
{
    return nullptr;
}

GameClient *Win32GameEngine::Create_Game_Client()
{
    return nullptr;
}

ModuleFactory *Win32GameEngine::Create_Module_Factory()
{
    return new W3DModuleFactory;
}

ThingFactory *Win32GameEngine::Create_Thing_Factory()
{
    return nullptr;
}

FunctionLexicon *Win32GameEngine::Create_Function_Lexicon()
{
    return new W3DFunctionLexicon;
}

Radar *Win32GameEngine::Create_Radar()
{
    return nullptr;
}

WebBrowser *Win32GameEngine::Create_Web_Browser()
{
    return nullptr;
}

ParticleSystemManager *Win32GameEngine::Create_Particle_System_Manager()
{
    return nullptr;
}

AudioManager *Win32GameEngine::Create_Audio_Manager()
{
#ifdef BUILD_WITH_MILES
    return new MilesAudioManager;
#else
    return nullptr;
#endif
}

Network *Win32GameEngine::Create_Network()
{
    return nullptr;
}
