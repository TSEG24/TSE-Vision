#include "application.h"

Application::Application(std::string outputFilepath, bool shouldRender) {
    output.open(outputFilepath);
}

Application::~Application() {
    output.close();
}

void Application::run() {

}

