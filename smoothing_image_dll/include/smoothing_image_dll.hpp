#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#if defined(SMOOTHING_IMAGE_DLL_SOURCE)
#	define SMOOTHING_IMAGE_DECL __declspec(dllexport)
#else
#	define SMOOTHING_IMAGE_DECL __declspec(dllimport)
#endif

#include <exception>
#include <iterator>
#include <cstdint>
#include <string>
#include <cmath>

SMOOTHING_IMAGE_DECL void gaussian_smoothing(float sigma, const std::string& in_img, const std::string& out_img);
