Student Indexing System (C)
This project implements a Student Management System using Singly Linked Lists with a Double Indexing strategy. It is designed to demonstrate efficient data management and memory allocation in C.

🚀 Features
Double Indexing: Access student records through two separate sorted linked lists: one by Student Number and one by Student Name.

Memory Efficiency: Uses dynamic memory allocation (malloc) for strings and structures, ensuring minimal memory footprint.

Sorted Insertion: Automatically maintains alphabetical and numerical order during the addition of new records.

Full CRUD Operations: * AddStudent: Insert new records.

DeleteStudent: Remove records from all indexes and free memory.

UpdateStudent: Modify existing records while maintaining index integrity.

SearchByStudentNumber & SearchByStudentName: Fast lookups in the respective index.

🛠️ Technical Details
The system uses a primary Student structure that holds the actual data, while two separate index structures (StudentNumberLL and StudentNameLL) point to this single source of truth using pointers (addr).

💻 How to Run
Clone the repository:

Bash
git clone https://github.com/kayrahansarnic00/student-indexing-system.git
Compile the source code:

Bash
gcc Project1.c -o student_system
Run the executable:

Bash
./student_system
