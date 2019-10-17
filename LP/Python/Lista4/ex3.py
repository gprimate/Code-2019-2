def enumerate_(iterator, start=0):
    i = start

    for item in iterator:
        yield i, item
        i += 1