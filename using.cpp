#include "api.h"

int main() {
	gmshInit();
	Pyramid pyramid01 = Pyramid("pyramid01", 0, 0, 0, 20, 30);
	pyramid01.init();
	pyramid01.build();
}

