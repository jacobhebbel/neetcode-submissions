class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        def get_flat_square(idx: int, board: List[List[str]]) -> List[str]:

            NUM_ROWS = 3
            NUM_COLS = 3

            row_start = idx // NUM_ROWS * 3
            col_start = idx % NUM_COLS * 3
            
            print(f'This square starts at ({row_start}, {col_start})')
            square = [
                row[col_start:col_start + 3] for row in board[row_start:row_start + 3]
            ]
            flat_square = [num for row in square for num in row]
            return flat_square

        def check_rows(board: List[List[str]]) -> bool:
            
            for row in board:
                num_list = [s for s in row if s != "."]
                num_set = set(num_list)
                if len(num_list) != len(num_set): return False

            return True

        def check_cols(board: List[List[str]]) -> bool:

            for col_idx in range(0, 9):
                col_list = [board[i][col_idx] for i in range(0, 9)]
                print('Evaluating Column: \n', col_list)
                
                num_list = [n for n in col_list if n != "."]
                num_set = set(num_list)
                if len(num_list) != len(num_set): return False
            
            return True

        def check_squares(board: List[List[str]]) -> bool:

            for square_idx in range(0, 9):
                square = get_flat_square(square_idx, board)

                print(square)
                num_list = [n for n in square if n != '.']
                num_set = set(num_list)

                if len(num_list) != len(num_set): return False

            return True

        valid_rows = check_rows(board)
        valid_cols = check_cols(board)
        valid_squares = check_squares(board)
        
        print(valid_rows)
        print(valid_cols)
        print(valid_squares)
        if valid_rows and valid_cols and valid_squares: return True
        else: return False