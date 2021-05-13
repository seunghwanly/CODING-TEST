def solution(board, moves):
    answer = 0
    basket = []
    # moves -> board[Y][move]
    for move in moves:
        for i in range(len(board)):
            # get top
            if board[i][move - 1] != 0:
                basket.append(board[i][move - 1])
                board[i][move - 1] = 0
                break
        # in basket
        if len(basket) > 1:
            if basket[len(basket) - 1] == basket[len(basket) - 2]:
                for j in range(2): 
                    basket.pop()
                    answer += 1        

    return answer

print(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]], [1,5,3,5,1,2,1,4]))