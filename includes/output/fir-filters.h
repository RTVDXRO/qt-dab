#
/*
 *    Copyright (C) 2010, 2011, 2012
 *    Jan van Katwijk (J.vanKatwijk@gmail.com)
 *    Lazy Chair Computing
 *
 *    This file is part of Qt-DAB
 *
 *    Qt-DAB is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    Q@t-DAB is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Qt-DAB; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __FIR_LOWPASSFILTER__
#define __FIR_LOWPASSFILTER__

#include	"dab-constants.h"
#include	<vector>

class	LowPassFIR {
public:
			LowPassFIR (int16_t,	// order
	                            int32_t, 	// cutoff frequency
	                            int32_t	// samplerate
	                           );
			~LowPassFIR ();
	std::complex<float>	Pass		(std::complex<float>);
	float			Pass		(float);
	void			resize		(int);
	int			theSize		();
private:
	int16_t		filterSize;
	int16_t		ip;
	std::vector<float>	filterKernel;
	std::vector<std::complex<float>>	Buffer;
	float		frequency;
};

#endif

