#include "classes.h"

int main(int argc, char **)
{
    auto csv_file = new FileReader("data.csv");
    auto csv_document = new CSVParser();

    std::string line;
    while ((line = csv_file->get_line()) != "") {
        csv_document->parse_line(line);
    }

    std::cout << "[0, 0] = " << csv_document->get_value(0, 0) << std::endl;
    delete csv_file;
}
