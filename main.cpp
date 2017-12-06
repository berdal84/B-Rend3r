
#include <cstdlib>
#include <iostream>

#include "src/BRend3r.h"

int main(int argc, char* argv[]) {

	BRend3r app;

	app.initialize();

    while( app.update())
    {
    	app.draw();
    }

    app.shutdown();

	return EXIT_SUCCESS;
}
