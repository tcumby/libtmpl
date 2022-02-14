

import regina
import ast


DTList = [
    "4 8 -12 2 -16 -6 -20 -18 -10 -14",
    "6 10 14 -18 2 -20 4 22 24 -8 -12 16",
    "8 -12 -16 -20 22 -2 24 -4 26 -6 28 10 14 18"
]

TorusList = [
    [
        [1, 7, 2, 6], [3, 9, 4, 8], [5, 1, 6, 10], [7, 3, 8, 2], [9, 5, 10, 4]
    ],
    [
        [1, 9, 2, 8], [3, 11, 4, 10], [5, 13, 6, 12], [7, 1, 8, 14],
        [9, 3, 10, 2], [11, 5, 12, 4], [13, 7, 14, 6]
    ],
    [
        [1, 13, 2, 12], [3, 15, 4, 14], [5, 17, 6, 16], [7, 19, 8, 18],
        [9, 21, 10, 20], [11, 1, 12, 22], [13, 3, 14, 2], [15, 5, 16, 4],
        [17, 7, 18, 6], [19, 9, 20, 8], [21, 11, 22, 10]
    ]
]

MirrorList = [
    [
        [1, 6, 2, 7], [3, 8, 4, 9], [5, 10, 6, 1], [7, 2, 8, 3], [9, 4, 10, 5]
    ],
    [
        [1, 8, 2, 9], [3, 10, 4, 11], [5, 12, 6, 13], [7, 14, 8, 1],
        [9, 2, 10, 3], [11, 4, 12, 5], [13, 6, 14, 7]
    ],
    [
        [1, 12, 2, 13], [3, 14, 4, 15], [5, 16, 6, 17], [7, 18, 8, 19],
        [9, 20, 10, 21], [11, 22, 12, 1], [13, 2, 14, 3], [15, 4, 16, 5],
        [17, 6, 18, 7], [19, 8, 20, 9], [21, 10, 22, 11]
    ]
]

for n in range(3):
    KnotRegina = regina.Link.fromDT(DTList[n])
    pd = list(ast.literal_eval(((KnotRegina.pd())[3:-1]).replace("X", "")))

    Knot = Link(pd)
    Tor = Link(TorusList[n])
    Mir = Link(MirrorList[n])

    hom = Knot.khovanov_homology()
    torhom = Tor.khovanov_homology()
    mirhom = Mir.khovanov_homology()
    print(hom, "\n")
    print(torhom, "\n")
    print(mirhom, "\n")

    if hom == torhom:
        print("MATCH")
    elif hom == mirhom:
        print("MATCH")
