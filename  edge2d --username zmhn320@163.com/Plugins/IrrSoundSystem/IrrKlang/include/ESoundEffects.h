// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __E_SOUND_EFFECTS_H_INCLUDED__
#define __E_SOUND_EFFECTS_H_INCLUDED__

namespace irr
{
namespace audio  
{
	//! An enumeration for all available sound effects. 
	/* They are usable in ISound::enableEffect() and ISound::disableEffect(). */
	enum E_SOUND_EFFECTS
	{
		/** If specified (default), it will make irrKlang run in a separate thread, updating
		all streams, sounds, 3d positions and whatever automaticly. You also don't need to call ISoundEngine::update()
		if irrKlang is running multithreaded. However, if you want to run irrKlang in the same thread
		as your application (for easier debugging for example), don't set this. But you need to call ISoundEngine::update()
		as often as you can (at least about 2-3 times per second) to make irrKlang update everything correctly then. */
		ESEO_MULTI_THREADED = 0x01,

		/** If the window of the application doesn't have the focus, irrKlang will be silent 
		if this has been set. This will only work when irrKlang is using the
		DirectSound output driver. */
		ESEO_MUTE_IF_NOT_FOCUSED = 0x02,

		//! Automaticly loads external plugins when starting up.
		/** Plugins usually are .dll 
		files named for example ikpMP3.dll (= short for irrKlangPluginMP3) which are executed
		after the startup of the sound engine and modify it for example to make it possible
		to play back mp3 files. Plugins are being loaded from the current working directory 
		as well as from the position where the .exe using the irrKlang library resides. */
		ESEO_LOAD_PLUGINS = 0x04,

		//! Uses 3D sound buffers instead of emulating them when playing 3d sounds (default).
		/** If this flag is not specified, all buffers will by created
		in 2D only and 3D positioning will be emulated in software, making the engine run
		faster if hardware 3d audio is slow on the system.  */
		ESEO_USE_3D_BUFFERS = 0x08,

		//! In addition to printing debug info to stdout, irrKlang will print debug info
		//! to any windows debugger supporting OutputDebugString() (like VisualStudio).
		//! This is pretty useful if your application does not capture any console output.
		ESEO_PRINT_DEBUG_INFO_TO_DEBUGGER = 0x10,

		//! If specified, instead of the default logarithmic one, irrKlang will 
		//! use a linear rolloff model which influences the attenuation 
		//! of the sounds over distance. The volume is interpolated linearly between the MinDistance
		//! and MaxDistance, making it possible to adjust sounds more easily although this is not
		//! physically correct.
		//! Note that this option may not work when used together with the ESEO_USE_3D_BUFFERS
		//! option when using Direct3D for example, irrKlang will then turn off ESEO_USE_3D_BUFFERS
		//! automaticly to be able to use this option and write out a warning.
		ESEO_LINEAR_ROLLOFF = 0x20,

		//! Default parameters when starting up the engine.
		ESEO_DEFAULT_OPTIONS = ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS | ESEO_PRINT_DEBUG_INFO_TO_DEBUGGER,

		//! This enumeration literal is never used, it only forces the compiler to 
		//! compile these enumeration values to 32 bit.
		ESEO_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace audio
} // end namespace irr


#endif

