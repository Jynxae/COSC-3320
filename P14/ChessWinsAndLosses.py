
from typing import List

ChessWinsandLosses = ['W','L','L','L']

def chess(chess, cond):
    if len(ChessWinsandLosses) <= 3:
        return
    else:
        half = len(ChessWinsandLosses)//2
        ChessWinsandLosses.split(half)
        chess(ChessWinsandLosses,True)
    
    Lcount = ChessWinsandLosses.count('L')
    Wcount = ChessWinsandLosses.count('W') #We make its own count cause we wanna check if there has been any W by itself in the last 4 games
    Dcount = ChessWinsandLosses.count('D')
    WDcount = ChessWinsandLosses.count('D') + ChessWinsandLosses.count('W')

    if Wcount == 0:
        cond = False

    #Checck to see in the last 3 games if there has been more L than W+D
        #cond = False


    #Check to see if there any W in the last 4 games
        #cond = False
    
    #if all passes then we do
    #cond = True