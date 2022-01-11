#include "smoothing_image_dll.hpp"

using namespace std;

#include <iostream> //debug

template<class T>
class matrix_interface {
public:
	matrix_interface(T* array, int width)
		: m_array(array), m_width(width) { }

	T& operator()(size_t i1, size_t i2) {
		return m_array[i1 * (m_width + 1) + i2];
	}

private:
	T* m_array;
	const int m_width;
};


string parse_type_of_image(const string& path_img) {
	auto it_end_of_type = path_img.end();
	auto it_begin_of_type = path_img.end();
	advance(it_begin_of_type, -4);

	return string(it_begin_of_type, it_end_of_type);
}

SMOOTHING_IMAGE_DECL void gaussian_smoothing(float sigma, const string& in_path_img, const string& out_path_img) {
	int width = 0, height = 0, component = 0;

	string type_of_image = parse_type_of_image(in_path_img);

	if (type_of_image == parse_type_of_image(out_path_img)) {
		if (type_of_image == ".jpg")
			component = 4;
		else if (type_of_image == ".png")
			component = 3;
		else
			throw(invalid_argument("Error. The file has not extension .jpg or .png."));
	}
	else
		throw(invalid_argument("Error. The data types of the files must be same."));
	

	uint8_t *rgb_image = stbi_load(in_path_img.c_str(), &width, &height, &component, component);
	//

	for (size_t i = 1; i <= 3; i++) {
		for (size_t j = 0; j < width * height * component; j += i ) {

			//Gaussian smoothing

		}
	}

	//
	stbi_write_png(out_path_img.c_str(), width, height, component, rgb_image, width * component);
	stbi_image_free(rgb_image);
}