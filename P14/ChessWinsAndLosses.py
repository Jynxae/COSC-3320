from typing import List
import sys

def chessFun(chess, cond):
    if len(chess) <= 3:
        return
    else:
        half = len(chess)//2
        chess = chess[half:]  #splice is how we can use it to cute a list in half. split() will make each character its own
        chessFun(chess,True)
    
    if cond == False:   #if the condition is false, no point in going thru the function, just keep returning false
        return False

    Wcount = chess.count('W') #We make its own count cause we wanna check if there has been any W by itself in the last 4 games

    if Wcount == 0:
        cond = False
        return False

    #Checck to see in the last 3 games if there has been more L than W+D. ONLY LAST 3 GAMES!!!!!!!!!!
    #IF         L                     IN THE LAST 3 SPOTS        IS GREATER THAN             W+D                      IN THE LAST 3 SPOTS
    if chess[-3:].count('L') > chess[-3:].count('W') + chess[-3:].count('D'):
       cond = False
       return False


    #Check to see if there any W in the last 4 games
    if chess[-4:].count('W'):
        cond = False
        return False
    
    #If we win all the games, then we keep the game condition true
    if cond == True:
        return True
    else:
        return False

ChessWinsandLosses = ['W','W','W']
#ChessWinsandLosses = sys.stdin.readline().split()
result = chessFun(ChessWinsandLosses, True)

if result == False:
    print("F")
else:
    print("T")