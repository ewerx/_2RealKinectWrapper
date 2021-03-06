/*
	CADET - Center for Advances in Digital Entertainment Technologies
	Copyright 2011 University of Applied Science Salzburg / MultiMediaTechnology

	http://www.cadet.at
	http://multimediatechnology.at/

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

	CADET - Center for Advances in Digital Entertainment Technologies

	Authors: Robert Praxmarer, Gerlinde Emsenhuber, Robert Sommeregger
	Email: support@cadet.at
	Created: 08-09-2011
*/

#pragma once

#include "OpenNISpecific/OpenNIGenerator.h"
#include <vector>

namespace _2Real
{

template <typename T> class _2RealImageSource;

class OpenNIColorGenerator : public OpenNIGenerator
{
	public:

		OpenNIColorGenerator();
		~OpenNIColorGenerator();

		XnStatus				startGenerating();
		XnStatus				stopGenerating();	
		bool					isGenerating() const;	

		// lock the generator so that no changes can be made to it's configuration without the lock handle
		XnStatus				lockGenerator();
		// unlock the generator so that changes can be made to it's configuration
		XnStatus				unlockGenerator();
		XnStatus				registerCallbacks();
		// set the output mode
		XnStatus				setOutputMode( const XnMapOutputMode outputMode );
		// return the error state
		XnStatus				getErrorState() const;
		// get the timestamp of the currently available data
		XnStatus				getTimestamp( uint64_t& time ) const;
		// enable or disable mirroring
		XnStatus				setMirroring( const bool mirror );
		// return current fps
		XnStatus				getFramesPerSecond(int &fps) const;
		// return resolution
		XnStatus				getMapResolution( uint32_t& x, uint32_t& y ) const;
		// get the current color data	
		XnStatus				getData( _2RealImageSource<uint8_t>& data ) const;
		//get mirror setting
		bool					isMirrored() const;


		// the XNImageGenerator
		xn::ImageGenerator	m_ColorGenerator;
		//lock handle
		XnLockHandle		m_ColorLock;
};

}