#include <stdio.h>

#include "print_module.h"
#include "documentation_module.h"

int main() {
    print_log(print_char, "Module_load_successb");
    #ifdef DOC
    short availability_mask;
    availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    print_document_status(availability_mask, Documents_count, Documents);
	#endif // DOC
    return 0;
}
