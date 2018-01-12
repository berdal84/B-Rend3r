
#include <cstdlib>
#include <iostream>

#include "src/BRender.h"

using namespace brd;

int main(int argc, char* argv[]) {

	BRender app;

	app.initialize();

    while( app.update())
    {
    	app.draw();
    }

    app.shutdown();

	return EXIT_SUCCESS;
}
