
from typing import List

def chess(chess, cond):
    if len(chess) <= 3:
        return
    else:
        half = len(chess)//2
        chess = chess.split(half)
        chess(chess,True)
    
    Wcount = chess.count('W') #We make its own count cause we wanna check if there has been any W by itself in the last 4 games

    if Wcount == 0:
        cond = False
        return

    #Checck to see in the last 3 games if there has been more L than W+D. ONLY LAST 3 GAMES!!!!!!!!!!
    #IF         L                     IN THE LAST 3 SPOTS        IS GREATER THAN             W+D                      IN THE LAST 3 SPOTS
    if chess.count('L') in chess[-3:] > chess.count('W') + chess.count('D') in chess[-3:]:
       cond = False
       return


    #Check to see if there any W in the last 4 games
    if chess.count('W') == 0 in chess[-4:]:
        cond = False
        return
    
    #If we win all the games, then we keep the game condition true
    cond = True
    return

ChessWinsandLosses = ['W','L','L','L']
result = chess(ChessWinsandLosses, True)

if result == False:
    print("False")
else:
    print("True")