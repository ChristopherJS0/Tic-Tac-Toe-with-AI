<h1>Tic-Tac-Toe w/ Alpha Beta Pruning AI</h1>
<b>The impossible game of Tic-Tac-Toe!</b>
<p>Play by entering a row number (by its index!) and then entering a column number (again by its index) to place your choice.
From there, using the mini max algorithm along with alpha beta pruning, an ai player will place their option next. 
You can try all options to start and end from but you'll start to notice that this game of Tic-Tac-Toe is impossible to win for you!</p>

<b>Tic-Tac-Toe</b>
<ul>
  <li>Constructor(): Puts empty spaces (' ') in its game board and fills the vector of vectors of chars with enough rows and columns for a Tic Tac Toe game.</li>
  <li>PrintBoard(): Prints all elements in the object's game board, even if they're blank. Also seperates columns with '|'s.</li>
  <li>Insert(): Using a row, column integers and a char representing the player's X or O, it will fill a VALID space on it's board using the current player's symbol.</li>
  <li>TerminalState(): Read's the board and calls the functions VerticalWin, HorizWin, DiagonalWin, to check for a winner and if there is one it will return the char of the winner.
    Also calls TieGame to detect if there are no winners but there are no more spaces to play, this returns ' ' to indicate a tie. If there are still more places to play and no player
    has won, it'll return '-' to indicate the game is still playable.</li>
  <li>DiagonalWin(): Loops through the board looking for a diagonal win and returns the winner player's char if there is a winner. Otherwise, it returns ' ' to indicate no winner.</li>
  <li>VerticalWin(): Loops through the board looking for a vertical win and returns the winner player's char if there is a winner. Otherwise, it returns ' ' to indicate no winner.</li>
  <li>HorizWin(): Loops through the board looking for a horizontal win and returns the winner player's char if there is a winner. Otherwise, it returns ' ' to indicate no winner.</li>
  <li>TieGame(): Loops through the entire board to detect if there are more playable spot(s), if all spots are filled, then it'll return true, otherwise it'll return false.</li>
  <li>TTTBoard: A vector holding vectors holding char elements to represent a Tic Tac Toe board.</li>
  <li>GameOver: A boolean to represent if the game is over.</li>
</ul>

<b>Triple</b>
<p>A struct containing 3 integers. The row index, the column index, and the score of the game which is either 0 or 1. In hindsight, I would've chosen a better name for this struct.</p>

<h2>Min-Max Algorithm and Alpha Beta Pruning</h2>
