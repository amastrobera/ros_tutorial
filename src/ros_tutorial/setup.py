from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['ros_tutorial'],
    scripts=['scripts/listener.py','scripts/talker.py',
             'scripts/client.py', 'scripts/server.py'],
    package_dir={'': 'src'}
)

setup(**d)