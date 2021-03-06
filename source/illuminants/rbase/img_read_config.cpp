/*	
	Copyright(c) 2012 Christian Riess <christian.riess@cs.fau.de>
	and Johannes Jordan <johannes.jordan@cs.fau.de>.

	This file may be licensed under the terms of of the GNU General Public
	License, version 3, as published by the Free Software Foundation. You can
	find it here: http://www.gnu.org/licenses/gpl.html
*/

#include "img_read_config.h"

using namespace boost::program_options;

namespace iread {

IReadConfig::IReadConfig(const std::string& prefix) :
	Config(prefix)
{
	#ifdef WITH_BOOST
		initBoostOptions();
	#endif // WITH_BOOST
}

std::string IReadConfig::getString() const
{
	std::stringstream s;

	if (prefix_enabled) {
		s << "[" << prefix << "]" << std::endl;
	}
	s << "image=" << imageFile << " # input image (3 channels, 8- or 16-bit colors/channel)" << std::endl
	  << "dark_level=" << dark_level << " # intensities below dark level are set to 0" << std::endl
	  << "saturation_level=" << saturation_level << " # intensities above saturation level are clipped" << std::endl
	  << "color_space=" << color_space << " # the input color space ('rgb' for linear rgb, 'srgb' for gamma'd sRGB)" << std::endl
	;

	return s.str();
}

#ifdef WITH_BOOST
void IReadConfig::initBoostOptions()
{
	options.add_options()
		(key("image,I"), value(&imageFile)->default_value(""), "input image (3 channels, 8- or 16-bit colors/channel)")
		(key("dark_level,D"), value(&dark_level)->default_value(0), "intensities below dark level are set to 0")
		(key("saturation_level,S"), value(&saturation_level)->default_value(-1), "intensities above saturation level are clipped")
		(key("color_space,C"), value(&color_space)->default_value(""), "the input color space ('rgb' for linear rgb, 'srgb' for gamma'd sRGB)")
	;
}
#endif // WITH_BOOST

} // namespace iread

