/*	
	Copyright(c) 2012 Christian Riess <christian.riess@cs.fau.de>
	and Johannes Jordan <johannes.jordan@cs.fau.de>.

	This file may be licensed under the terms of of the GNU General Public
	License, version 3, as published by the Free Software Foundation. You can
	find it here: http://www.gnu.org/licenses/gpl.html
*/

#ifndef ILLUMESTIMATORS_COMMON_MASK_H
#define ILLUMESTIMATORS_COMMON_MASK_H

#include "superpixel.h"
#include <opencv2/core/core.hpp>
#include <vector>

namespace illumestimators {

/** The mask class provides helper functions for handling image masks.
 *  Masks are stored as matrices of the type unsigned char.
 *  Values greater than zero indicate masked pixels.
 */
class Mask
{
public:
	/** Extract masked pixels from an image.
	 *  \param image Input image.
	 *  \param image Input mask belonging to the input image.
	 *  \return Image vector with masked pixels.
	 */
	static std::vector<cv::Vec3d> maskedPixels(const cv::Mat_<cv::Vec3d>& image, const cv::Mat_<unsigned char>& mask);
	/** Extract unmasked pixels from an image.
	 *  \param image Input image.
	 *  \param image Input mask belonging to the input image.
	 *  \return Image vector with unmasked pixels.
	 */
	static std::vector<cv::Vec3d> unmaskedPixels(const cv::Mat_<cv::Vec3d>& image, const cv::Mat_<unsigned char>& mask);
	/** Extract masked pixels from a superpixel of an image.
	 *  \param image Input image.
	 *  \param superpixel Image coordinates of the superpixel.
	 *  \param image Input mask belonging to the input image.
	 *  \return Image vector with masked pixels.
	 */
	static std::vector<cv::Vec3d> maskedPixels(const cv::Mat_<cv::Vec3d>& image, const superpixels::Superpixel& superpixel, const cv::Mat_<unsigned char>& mask);
	/** Extract unmasked pixels from a superpixel of an image.
	 *  \param image Input image.
	 *  \param superpixel Image coordinates of the superpixel.
	 *  \param image Input mask belonging to the input image.
	 *  \return Image vector with unmasked pixels.
	 */
	static std::vector<cv::Vec3d> unmaskedPixels(const cv::Mat_<cv::Vec3d>& image, const superpixels::Superpixel& superpixel, const cv::Mat_<unsigned char>& mask);

public:
	/** Mask pixels with a color component greater or equal a given threshold.
	 *  \param image Input image.
	 *  \param image Input mask belonging to the input image.
	 *  \param threshold Threshold.
	 */
	static void maskSaturatedPixels(const cv::Mat_<cv::Vec3d>& image, cv::Mat_<unsigned char>& mask, double threshold);
	/** Mask pixels with a color component smaller than a given threshold.
	 *  \param image Input image.
	 *  \param image Input mask belonging to the input image.
	 *  \param threshold Threshold.
	 */
	static void maskMinPixels(const cv::Mat_<cv::Vec3d>& image, cv::Mat_<unsigned char>& mask, double threshold);
	/** Mask pixels with the sum of the color component smaller than a given threshold.
	 *  \param image Input image.
	 *  \param image Input mask belonging to the input image.
	 *  \param threshold Threshold.
	 */
	static void maskDarkPixels(const cv::Mat_<cv::Vec3d>& image, cv::Mat_<unsigned char>& mask, double threshold);
	/** Mask pixels at the borders of the image.
	 *  \param image Input image.
	 *  \param image Input mask belonging to the input image.
	 *  \param threshold Width of the border mask in pixels.
	 */
	static void maskBorderPixels(const cv::Mat_<cv::Vec3d>& image, cv::Mat_<unsigned char>& mask, int width);

public:
	/** Create mask from superpixel.
	 *  \param image Input image.
	 *  \param superpixel Superpixel.
	 *  \param maskSuperpixels Mask the superpixel coordinates.
	 *  \return Created mask.
	 */
	static cv::Mat_<unsigned char> fromSuperpixel(const cv::Mat_<cv::Vec3d>& image, const superpixels::Superpixel& superpixel, bool maskSuperpixel = false);
};

} // namespace illumestimators

#endif // ILLUMESTIMATORS_COMMON_MASK_H
