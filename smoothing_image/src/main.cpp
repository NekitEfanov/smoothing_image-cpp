#include "smoothing_image_dll.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	int sigma = 0;
	string in_path_img, out_path_img;

	for (size_t i = 1; i < argc; i++) {
		cout << "Command: " << argv[i] << '\t';

		if (i + 1 < argc) {
			if (string(argv[i]) == string("--sigma")) {
				sigma = atoi(argv[i + 1]);
				cout << " " << argv[i + 1] << endl;
				i++;
			}
			else if (string(argv[i]) == string("--input")) {
				in_path_img = string(argv[i + 1]);
				cout << " " << argv[i + 1] << endl;
				i++;
			}
			else if (string(argv[i]) == string("--output")) {
				out_path_img = string(argv[i + 1]);
				cout << " " << argv[i + 1] << endl;
				i++;
			}
		}
		else
			cout << endl;
	}

	if (sigma > 0 && !in_path_img.empty() && !out_path_img.empty()) {
		try {
			gaussian_smoothing(sigma, in_path_img, out_path_img);
		}
		catch (const std::exception& ex) {
			cout << ex.what() << endl;
			return 0;
		}

		cout << "finished." << endl;
	}
	else
		cout << "Error. Invalid argumets." << endl;

	return 0;
}