# 🏆 Graphs & Rankings in Tournaments — Inspired by **Lanparty** 🎮

Welcome to a project that takes the simple idea of tournament rankings to the next level using **graphs** and **network analysis**! Based on the simulation from **Lanparty** (our previous repo 🕹️), this project dives deeper into what it means to **rank players fairly** in competitive scenarios.

---

## 🎯 Problem Description

In a single tournament (like the one we simulated in **Lanparty**), ranking players is straightforward:

- 🥇 Winner of the final = 1st place
- ❌ Player who lost all matches = last place

But what happens when we consider results from **multiple tournaments**? 🤔  
Two players may have the same number of wins, but not all wins are equal — for example, a win against a world champion should count more than one against a beginner.

That’s where **graph-based ranking** comes in. This approach is increasingly used in real-world sports analytics 🏀⚽🏐 and relies on network properties to build more nuanced, fair rankings.

---

## 🔗 Graph Modeling of Victories

We model players and their victories using a **directed graph**:

- 🎯 Each **node** = a player or team  
- 🔁 A **directed edge** from player A to player B means: **A lost to B**

Depending on how many matches two players had, we can:
- Use a **multigraph** (multiple edges per match)
- Or a **weighted graph**, where the edge weight = number of wins

This forms a **Victory Graph** 🕸️ where edge thickness or weight reflects how dominant one player is over another.

---

## 📊 Ranking Using Graph Centrality

To compute the final ranking (or **prestige**) of each player, we use a method similar to **PageRank** — the algorithm Google originally used to rank websites 🌐📈.

### Key Idea:
> A player is important not just by how many wins they have, but **who they beat**.  
> Beating strong players increases your prestige more than beating weak ones.

This concept is called **centrality**, and it's calculated through **iterative methods** (covered in more detail in Year 2 📚).

---

## 🔧 What You Have to Do

### ✅ 1. Build the Victory Graph
Just like the one in Figure 1.1 (panel C) from Radicchi’s paper 📘.

### ✅ 2. Compute Team Prestige
Using the prestige formula (Equation 1), with a damping factor `q = 0.15` 🧮  
Write the prestige of each team in a file, formatted like:
0.5312 TeamName
0.3278 AnotherTeam

Sorted, of course, by importance 😉

---

## 📚 References

- [1] Brin & Page, *The Anatomy of a Large-Scale Hypertextual Web Search Engine*, 1998.
- [2–4] Various tournament and graph theory research.
- [5] Radicchi, *Who is the best player ever?*, PLoS ONE, 2011.

---

## 💡 Notes

This project builds on the **Lanparty** repo (from our earlier homework) and takes it further by introducing network-based thinking for tournament analysis. Perfect for those curious about data science, networks, and competitive fairness 🧠⚖️.

---

**Let the smartest player win — not just the one with the most easy matches!** 🎲👑


