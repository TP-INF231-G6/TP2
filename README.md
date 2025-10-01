\documentclass[a4paper,12pt]{article}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[french]{babel}
\usepackage{hyperref}
\usepackage{listings}
\usepackage{xcolor}

\lstset{
    basicstyle=\ttfamily,
    keywordstyle=\color{blue}\ttfamily,
    commentstyle=\color{gray}\ttfamily,
    stringstyle=\color{red}\ttfamily,
    showstringspaces=false,
    breaklines=true,
}

\title{INF 231\_EC2 : Structure de Données II -- Exercices en Algorithmique}
\author{Projet collaboratif -- Groupe de TP}
\date{}

\begin{document}

\maketitle

\section*{👨🏾‍🏫 Enseignant responsable}
\textbf{PR. Metatagia}

\section*{👥 Groupe de TP}
Projet collaboratif -- exercices pratiques en \textbf{C (implémentation des structures de données).}

\section*{📌 Objectifs du TP}
Ce dépôt regroupe les implémentations en \textbf{langage C} de différents exercices liés aux \textbf{listes chaînées} (simples, doubles et circulaires).  
Chaque programme est documenté et organisé par dossier pour faciliter la lecture et la collaboration.

\section*{📂 Contenu des exercices}
\begin{enumerate}
    \item \textbf{Liste simplement chaînée}
    \begin{itemize}
        \item Suppression de toutes les occurrences d’un élément
        \item Insertion dans une liste triée
    \end{itemize}

    \item \textbf{Liste doublement chaînée}
    \begin{itemize}
        \item Insertion dans une liste triée
    \end{itemize}

    \item \textbf{Liste simplement chaînée circulaire}
    \begin{itemize}
        \item Insertion en tête
        \item Insertion en queue
    \end{itemize}

    \item \textbf{Liste doublement chaînée circulaire}
    \begin{itemize}
        \item Insertion en tête
        \item Insertion en queue
    \end{itemize}
\end{enumerate}

\section*{📖 Organisation du dépôt}
\begin{lstlisting}[language=bash]
.
├── README.md
├── docs/
│   ├── consignes.md
│   ├── 23U2498-TSANGA-AWANA-EUGENE-GONTRAN.md
│   ├── 24F2657-KEUBOU-FOTSA-WILLY.md
│   ├── 24F2810-TIETCHAK-TIAGO-ESTHERA-JOANNA.md
│   ├── 24G2060-ONANA-GREGOIRE-LEGRAND.md
│   ├── 24G2117-FUDJING-MANUEL-ERWIN.md
│   ├── 24G2333-Lembou-Ngueumedje-Pharel.md
│
├── Liste_simplement_chainee/
│   ├── suppression_occurence.c
│   ├── insertion_triee.c
│
├── Liste_doublement_chainee/
│   ├── insertion_triee.c
│
├── Liste_simplement_circulaire/
│   ├── insertion_en_tete.c
│   ├── insertion_en_queue.c
│
├── Liste_doublement_circulaire/
│   ├── insertion_en_tete.c
│   ├── insertion_en_queue.c
\end{lstlisting}

\section*{👤 Auteurs / Collaborateurs}
\begin{itemize}
    \item \href{https://github.com/erwin-cyberdev}{@erwin-cyberdev}
    \item \href{https://github.com/LembouPharel}{@LembouPharel}
    \item \href{https://github.com/psycho237-prog}{@psycho237-prog}
    \item \href{https://github.com/TSANGA-AWANA}{@TSANGA-AWANA}
    \item \href{https://github.com/Wills007-deep}{@Wills007-deep}
    \item \href{https://github.com/esthera-tiago}{@esthera-tiago}
\end{itemize}

\end{document}
