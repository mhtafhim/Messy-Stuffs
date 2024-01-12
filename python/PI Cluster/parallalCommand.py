from fabric import task

env = {
    'hosts': [
        'pi1@pi01.local',
        'pi2@pi02.local',
        'pi3@pi03.local',
        'pi4@pi04.local',
    ],
    'usernames': [
        'pi1',
        'pi2',
        'pi3',
        'pi4',
    ],
    'passwords': [
        'pi1234',
        'pi1234',
        'pi1234',
        'pi1234',
    ],
}

@task
def cmd(c, command):
    username = env.usernames[env.hosts.index(c.host)]
    password = env.passwords[env.hosts.index(c.host)]
    with c.prefix(f"sudo -u {username}"):
        c.sudo(command, password=password)
