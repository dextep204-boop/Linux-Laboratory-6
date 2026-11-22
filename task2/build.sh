
#!/bin/bash
set -e
g++ main.cpp print_up.cpp -o program
echo "Build completed successfully!"
./program "hello linux"
