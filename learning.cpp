#include <iostream>
#include <vector>


class Block{
    public:
        // to check if the block is grayed (answered or not)
        bool is_answered;

        // The color of each block (can only be yellow or blue)
        bool color;

        void sethasblock(bool has_answere) {is_answered = has_answere;}
        int gethasblock() const {return is_answered;}

        void setcolor(bool colored) {color = colored;}
        int getcolor() const {return color;}
        
        
};

int main() {
    int grid_size = 4;
    std::cout << "How large should the grid be? 4,6,8,10,12" << std::endl;
    std::cin >> grid_size;

    // Simple cekk i have to get a better metode for that but right now working
    while (grid_size > 0 && grid_size % 2 != 0)
    {
        std::cout << "To play the game selekt a grid size devisibil by 2" << std::endl;
        std::cin >> grid_size;
    }
    std::cout << grid_size << std::endl;

    std::vector<std::vector<Block>> matrix(grid_size, std::vector<Block>(grid_size));

    int counter = 1; 
    for (int row = 0; row < grid_size; ++row) {
        for (int col = 0; col < grid_size; ++col){
            if (row %3 != 0){
                matrix[row][col].sethasblock(true);
            }
            else{
               matrix[row][col].sethasblock(false); 
            }
            if (row % 2 == 0){
                matrix[row][col].setcolor(true); 
            }
            else{
                matrix[row][col].setcolor(false);
            }

        }
    }

    for(int row = 0; row < grid_size; ++row){
        for(int col = 0; col < grid_size; ++col){
            std::cout << matrix[row][col].gethasblock() << "/" << matrix[row][col].getcolor() << "\t";
        }
        std::cout << "\n";
    }


}