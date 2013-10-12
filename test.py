import blake_hash
import weakref
import binascii
import StringIO

from binascii import unhexlify
from binascii import hexlify
teststart = '000000ba5cae4648b1a2b823f84cc3424e5d96d7234b39c6bb42800b2c7639be';
testbin = unhexlify(teststart)
hash_bin = blake_hash.getPoWHash(testbin)
print(teststart)# DEBUG
out = hexlify(hash_bin)
print(out)	# DEBUG
