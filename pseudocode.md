# Pseudocode

START

Initialize board with numbers 1 to 9
Set currentPlayer = X
Set moveCount = 0

WHILE game not finished

    Display board

    Ask player for position

    IF position already taken
        Print "Invalid move"
        Continue loop
    ENDIF

    Place player symbol on board

    moveCount++

    IF winning condition satisfied
        Display board
        Print "Player wins"
        End game
    ENDIF

    IF moveCount == 9
        Display board
        Print "Game Draw"
        End game
    ENDIF

    Switch player

ENDWHILE

END
