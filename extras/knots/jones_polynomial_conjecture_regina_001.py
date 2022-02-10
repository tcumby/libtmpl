import regina
import numpy

# Largest number of twists we'll check for torus knots.
torus_start = 2
torus_end = 100
torus_count = 0
KnotList = []
MirrorList = []
TorusStringList = []
one = regina.Laurent(0)
one_minus_pow_neg_q = one - regina.Laurent(-4)
one_minus_pow_pos_q = one - regina.Laurent(4)

print("Reading table...")
fp = open("dt_code_0_13.txt")

print("Computing Jones polynomials of Torus Knots...")
for m in range(torus_start, torus_end):

    if (m == 0) or (m == 1) or (m == -1):
        continue

    for n in range(m+1, torus_end):

        if (n == 0) or (n == 1) or (n == -1):
            continue

        if (numpy.gcd(m, n) != 1):
            continue

        a = regina.Laurent((m-1)*(n-1))
        b = regina.Laurent(2*m+2)
        c = regina.Laurent(2*n+2)
        d = regina.Laurent(2*(m+n))

        f = a*(one - b - c + d)

        a = regina.Laurent((1-m)*(n-1))
        b = regina.Laurent(-2*m-2)
        c = regina.Laurent(-2*n-2)
        d = regina.Laurent(-2*(m+n))

        g = a*(one - b - c + d)

        KnotList.append(f)
        MirrorList.append(g)
        TorusStringList.append("(%d, %d)" % (m, n))
        torus_count += 1

print("Computing Jones Polynomial from Table")
for pd in fp:
    L = regina.Link.fromDT(pd)
    j = L.jones()
    f = j*one_minus_pow_pos_q
    fm = j*one_minus_pow_neg_q

    for n in range(torus_count):
        if KnotList[n] == f or MirrorList[n] == fm:
            print("Match: %s" % TorusStringList[n], "DT Code %s" % pd)

