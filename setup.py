from distutils.core import setup, Extension

blake_hash_module = Extension('blake_hash',
                               sources = ['blakemodule.c',
                                          'blake.c',
					  'sphlib/blake.c'],
                               include_dirs=['.', './sphlib'])

setup (name = 'blake_hash',
       version = '1.0',
       description = 'Bindings for blake proof of work used by Blakecoin',
       ext_modules = [blake_hash_module])
