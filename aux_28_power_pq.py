# ref: p54, elements of programming interviews

def power(p, q):
    result = 1.0
    if (q < 0.0):
        p = 1.0/p
        q = -q

    q_temp = q
    while (q_temp > 0):
        import pdb; pdb.set_trace()
        if (q_temp & 1 > 0):
            print (q_temp)
            result *= p

        p *= p
        q_temp >>= 1

    return result



if __name__ == '__main__':
    print(power(2, 6))
