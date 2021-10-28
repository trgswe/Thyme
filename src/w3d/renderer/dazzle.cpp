/**
 * @file
 *
 * @author Jonathan Wilson
 *
 * @brief dazzle
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "dazzle.h"
#ifdef GAME_DLL
#include "hooker.h"
#endif

PrototypeClass *DazzleLoaderClass::Load_W3D(ChunkLoadClass &cload)
{
#ifdef GAME_DLL
    return Call_Method<PrototypeClass *, DazzleLoaderClass, ChunkLoadClass &>(0x0084F0A0, this, cload);
#else
    return nullptr;
#endif
}
