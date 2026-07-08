# FSB - Discord bot
Source code of FSB, a private Discord bot. <br/>
This project is based on the [D++ library](https://github.com/brainboxdotcc/DPP). <br/>
Discord server using the bot: https://discord.gg/zkJ75UDVEV. <br/>

# 📦 Requirements
- CMake.
- MariaDB server.

# ⚙️ Configuration
In the `./config` server, you must create the file `fsb.config` and set the following config in there. <br/>
``` config
TOKEN=bot_token_here
DB_NAME=name_of_your_database
DB_HOST=database_address
DB_PORT=database_port
DB_USER=database_username
DB_PASSWORD=database_password
```

# 🖥️ Database setup
``` sql
- name_of_your_database
├── Table "config"
   ├── guild VARCHAR(255) PRIMARY KEY NOT NULL
   ├── member_role VARCHAR(255)
   ├── stateless_role VARCHAR(255)
   ├── welcome_channel VARCHAR(255)
```

# 📥 Installation
1) Download the project. <br/>
2) Set the `fsb.config` file. <br/>
3) Build and run using the `build.sh` script. <br/>
4) Enjoy! <br/>

# 🤝 User Agreement
By downloading and/or using this program, you confirm that you are solely responsible for how you use this software. You agree as well that this agreement extends to any prior version of the program, and any new version of the user agreement in any future update, overwrites this one.
