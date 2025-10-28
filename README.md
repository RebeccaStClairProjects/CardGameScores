<h1 style="text-align:center; font-size:2.5em;">Card Game Scores (C++ / Visual Studio)</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue.svg" alt="C++ Badge"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-purple.svg" alt="Visual Studio Badge"/>
  <img src="https://img.shields.io/badge/Focus-Score%20Tracking-brightgreen.svg" alt="Score Tracking Badge"/>
  <img src="https://img.shields.io/badge/License-MIT-lightgrey.svg" alt="License Badge"/>
</p>

<p style="font-size:1.1em;">A console-based score tracker and round recorder for multiple card games, implemented in modern <b>C++</b> with a Visual Studio solution.</p>

<blockquote><b>Who this is for:</b> Reviewers of my internship portfolio and peers interested in C++ console apps that model game rules, validate input, and persist basic history.</blockquote>

<hr>

<h2>Table of Contents</h2>
<ul>
  <li><a href="#overview">Overview</a></li>
  <li><a href="#games">Supported Games</a></li>
  <li><a href="#architecture">Architecture</a></li>
  <li><a href="#key-classes">Key Files & Classes</a></li>
  <li><a href="#getting-started">Getting Started</a></li>
  <li><a href="#usage">How to Use</a></li>
  <li><a href="#design-notes">Design Notes</a></li>
  <li><a href="#future-improvements">Future Improvements</a></li>
  <li><a href="#about-developer">About the Developer</a></li>
  <li><a href="#license">License</a></li>
</ul>

<hr>

<h2 id="overview">Overview</h2>
<p><b>Card Game Scores</b> is a small C++ console application for recording players, tracking round-by-round scores, and saving summaries to a simple text log. The repository contains a Visual Studio solution and several game modules.</p>

<hr>

<h2 id="games">Supported Games</h2>
<ul>
  <li><b>Phase 10</b> — scoring utilities and flow (<code>Phase10.cpp/.h</code>).</li>
  <li><b>Play Nine</b> — score calculation helpers (<code>PlayNine.cpp/.h</code>).</li>
  <li><b>UNO Flip</b> — basic tracking for UNO Flip rounds (<code>UnoFlip.cpp/.h</code>).</li>
</ul>
<p><i>Note:</i> The exact prompts and scoring details are kept simple and console-friendly for easy testing and demonstration.</p>

<hr>

<h2 id="architecture">Architecture</h2>
<pre>
CardGameScores/
  GameRecordingMain.cpp        // Program entry: menu + flow control
  Player.h                     // Player model (name, per-round totals)
  Phase10.cpp / Phase10.h      // Phase 10 scoring
  PlayNine.cpp / PlayNine.h    // Play Nine scoring
  UnoFlip.cpp / UnoFlip.h      // UNO Flip scoring
  GameHistory.txt              // Saved textual history output
  Phase10Recording.sln         // Visual Studio solution
  Phase10Recording.vcxproj*    // Visual Studio project files
</pre>

<hr>

<h2 id="key-classes">Key Files & Classes</h2>
<ul>
  <li><b><code>Player</code> (Player.h)</b>: Represents a player; stores name and scoring state.</li>
  <li><b><code>GameRecordingMain.cpp</code></b>: Entry point; top-level menu, user I/O, dispatch to game modules.</li>
  <li><b><code>Phase10</code></b>: Functions/utilities for Phase 10 rounds and scoring rules.</li>
  <li><b><code>PlayNine</code></b>: Helpers for Play Nine score evaluation.</li>
  <li><b><code>UnoFlip</code></b>: Basic routines for UNO Flip round tracking.</li>
</ul>

<hr>

<h2 id="getting-started">Getting Started</h2>
<h3>Prerequisites</h3>
<ul>
  <li>Windows with <b>Visual Studio</b> (C++ Desktop Development workload).</li>
</ul>

<h3>Build & Run</h3>
<ol>
  <li>Clone this repository.</li>
  <li>Open <code>Phase10Recording.sln</code> in Visual Studio.</li>
  <li>Select <b>Debug</b> or <b>Release</b>, then <b>Build</b> and <b>Run</b> (Ctrl+F5).</li>
</ol>

<hr>

<h2 id="usage">How to Use</h2>
<ol>
  <li>Launch the program.</li>
  <li>From the main menu, choose a game (Phase 10, Play Nine, or UNO Flip).</li>
  <li>Enter player names and follow prompts for round results / scores.</li>
  <li>When finished, check <code>GameHistory.txt</code> for a plain-text record of results.</li>
</ol>

<hr>

<h2 id="design-notes">Design Notes</h2>
<ul>
  <li><b>Modular games:</b> Each game’s logic is encapsulated in its own translation unit.</li>
  <li><b>Separation of concerns:</b> Game logic kept separate from I/O where practical for easier testing.</li>
  <li><b>History output:</b> Minimalistic logging to <code>GameHistory.txt</code> for quick review.</li>
</ul>

<hr>

<h2 id="future-improvements">Future Improvements</h2>
<ul>
  <li>Centralize input validation and error messages across all games.</li>
  <li>Add a <code>GameHistory.csv</code> export for spreadsheet analysis.</li>
  <li>Unit tests for score calculation edge cases (e.g., Phase 10 special hands, Play Nine negative-point combos).</li>
  <li>Configurable rulesets per game (house rules toggles).</li>
  <li>Optional JSON config for players and saved sessions.</li>
</ul>

<hr>

<h2 id="about-developer">About the Developer</h2>
<p><b>Rebecca St. Clair</b><br>
🎓 <i>Computer Science Student | Aspiring Software Engineer | Writer</i><br>
I enjoy building small, focused utilities that demonstrate object-oriented design and pragmatic problem-solving.</p>
<p>
  <a href="https://github.com/RebeccaStClairProjects"><img src="https://img.shields.io/badge/Portfolio-RebeccaStClairProjects-blue" alt="Portfolio Badge"></a><br>
  <a href="https://www.linkedin.com/in/rebecca-st-clair-553225236/"><img src="https://img.shields.io/badge/LinkedIn-Rebecca%20St.%20Clair-blue?logo=linkedin" alt="LinkedIn Badge"></a>
</p>

<hr>

<h2 id="license">License</h2>
<p>MIT License. See the <code>LICENSE</code> file for details.</p>
