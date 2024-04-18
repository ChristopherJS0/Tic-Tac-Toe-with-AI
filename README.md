<h1>Tic-Tac-Toe w/ Alpha Beta Pruning AI</h1>
<b>The impossible game of Tic-Tac-Toe!</b>
<p>Play by entering a row number (by its index!) and then entering a column number (again by its index) to place your choice.
From there, using the mini max algorithm along with alpha beta pruning, an ai player will place their option next. 
You can try all options to start and end from but you'll start to notice that this game of Tic-Tac-Toe is impossible to win for you!</p>

<h2>Min-Max Algorithm and Alpha Beta Pruning</h2>
<b>Minimax Algorithm</b>
<p>The mini-max algorithm is a turn based algorithm where it begins by choosing the best state/choice, otherwise known as maximizing. Next it chooses the 
worst state/choice, also known as minimizing the score, based off the state the previous maximum decision left the game in. 
This process repeats until a limit is met or until a terminal state is found. The algorithm assumes that the opponent makes the best possible decision
(in the opponent's perspective) when it makes the minimizing call. 
This is why a game like Tic-Tac-Toe is perfect for the minimax algorithm
because it is a zero-sum game with only 2 players and both working against each other.</p>
<b>Alpha Beta Pruning</b>
<p>The minimax algorithm is a great algorithm for finding the best decision
for the next play, however it can be pretty demanding with how many states
there are to choose from. Alpha beta pruning solves this problem by cutting
off states that won't be played.</p>

<p>Alpha stands for the maximum score a furthest called MAXIMIZING function 
has to pick from, it starts at negative infinity so it can easily get a maximum
value when it gets a terminal state with a score. Once the maximum call has
the updated alpha value, for every child state it has, if it finds a 
child state that is lesser than its alpha value, it'll "prune" the rest of the 
child states it has because it knows it already has a greater state to pick from. 
Since the minimax algorithm is recursive, the alpha 
value will be passed up to its parent and so on (if it has one, which will be a
minimizing function call). </p>

<p>Beta stands for the minimum value that a furthest called MINIMIZING 
function has to pick from, it starts at infinity so it can easily get a minimum
value when it gets a terminal state with a score. Once the minimum call has
the updated beta value, for every child state it has, if it finds a 
child state that is greater than its beta value, it'll "prune" the rest of the 
child states it has because it knows it already has a lesser state to pick from. 
Since the minimax algorithm is recursive, the beta 
value will be passed up to its parent and so on (if it has one, which will be a
maximizing function call).</p>