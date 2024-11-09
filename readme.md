# Readme

个人所用的 SourceMod 开发环境，上传项目为了保存历史记录，遵守开源协议所以公开源代码。

## 项目结构

- bin

    - plugins**

        存放编译后的插件

    - sm_**

        存放编译插件所需的工具

- ext (extensions)

    以子模块的方式存放拓展项目

    tips: 添加新的子模块后，需要配置 settings.json 否则可能找不到头文件

- inc (includes)

    存放纯 sourcepawn 的头文件

    存放在 ./inc/ 路径下的单文件的头文件无需配置 settings.json

    而以子模块形式或在子文件夹中的头文件需要配置 settings.json，否则可能找不到头文件

- plugins

    存放开发的插件

    建议另外创建单独的项目管理，然后使用如下指令添加

    ```
    git clone --recurse <url>
    ```

- sm_1_12

    sourcemod 1.12 版本的源码（当前最新稳定版本 2024/10/24）

- sm_latest

    sourcemod 的最新开发版本

- utils

    以子模块的方式存放工具插件

    这些插件主要用于提供 native 接口给其他插件调用，本身不含复杂的业务逻辑

    与 ext 不同，主要使用 sourcepawn 语言实现

    与 inc 不同，除了头文件还必须添加相关插件，提供的 native 才能正常工作

    tips: 添加新的子模块后，需要配置 settings.json 否则可能找不到头文件


## 使用

- 拉取项目（递归）

    ```
    git clone --recurse-submodules <url> <path>
    ```

    如果已经克隆了项目，且克隆时忘记添加参数 --recurse-submodules，可以使用如下命令初始化子项目
    ```
    git submodule update --init --recursive
    ```

- 配置环境（样例）

    VsCode 编辑器 + SourcePawn Studio (By Sarrus) 拓展

    - settings.json

        ```
        "sourcepawn.AuthorName": "F1F88",
        "sourcepawn.GithubName": "F1F88",
        "SourcePawnLanguageServer.eventsGameName": "No More Room In Hell",
        "sourcepawn.showCompileIconInEditorTitleMenu": true,    // 是否显示 "编译代码" 图标
        "sourcepawn.uploadToServerAfterCompile": false,         // 编译后上传文件
        "sourcepawn.runServerCommandsAfterCompile": false,      // 编译后运行指令
        "sourcepawn.availableAPIs": [
            {
                "name": "win_1_12",
                "includeDirectories": [
                    ".\\scripting\\include",
                    "D:\\Code\\sm\\ext",
                    "D:\\Code\\sm\\ext\\log4sp\\sourcemod\\scripting\\include",
                    "D:\\Code\\sm\\ext\\ripext\\pawn\\scripting\\include",
                    "D:\\Code\\sm\\ext\\socket\\scripting\\include",
                    "D:\\Code\\sm\\ext\\SteamWorks\\Pawn\\includes",
                    "D:\\Code\\sm\\inc",
                    "D:\\Code\\sm\\inc\\",
                    "D:\\Code\\sm\\inc\\json",
                    "D:\\Code\\sm\\inc\\localizer",
                    "D:\\Code\\sm\\inc\\multicolors\\addons\\sourcemod\\scripting\\include",
                    "D:\\Code\\sm\\inc\\nmrih-vscript-proxy",
                    "D:\\Code\\sm\\inc\\outputactions",
                    "D:\\Code\\sm\\inc\\queue\\scripting\\include",
                    "D:\\Code\\sm\\inc\\smlib2\\include",
                    "D:\\Code\\sm\\sm_1_12\\plugins\\include",
                    "D:\\Code\\sm\\utils",
                    "D:\\Code\\sm\\utils\\",
                    "D:\\Code\\sm\\utils\\chronobreak\\scripting\\include",
                    "D:\\Code\\sm\\utils\\dash\\scripting\\include",
                    "D:\\Code\\sm\\utils\\nmr-objective\\scripting\\include",
                    "D:\\Code\\sm\\utils\\nmr-player\\scripting\\include",
                ],
                "compilerPath": "D:\\Code\\sm\\bin\\sm_1_12\\spcomp.exe",
                "outputDirectoryPath": "D:\\Code\\sm\\bin\\plugins_1_12\\",
                "compilerArguments": []
            },
            {
                "name": "win_latest",
                "includeDirectories": [
                    ".\\scripting\\include",
                    "D:\\Code\\sm\\ext\\log4sp\\sourcemod\\scripting\\include",
                    "D:\\Code\\sm\\ext\\ripext\\pawn\\scripting\\include",
                    "D:\\Code\\sm\\ext\\socket\\scripting\\include",
                    "D:\\Code\\sm\\ext\\SteamWorks\\Pawn\\includes",
                    "D:\\Code\\sm\\inc",
                    "D:\\Code\\sm\\inc\\",
                    "D:\\Code\\sm\\inc\\json",
                    "D:\\Code\\sm\\inc\\localizer",
                    "D:\\Code\\sm\\inc\\multicolors\\addons\\sourcemod\\scripting\\include",
                    "D:\\Code\\sm\\inc\\nmrih-vscript-proxy",
                    "D:\\Code\\sm\\inc\\outputactions",
                    "D:\\Code\\sm\\inc\\queue\\scripting\\include",
                    "D:\\Code\\sm\\inc\\smlib2\\include",
                    "D:\\Code\\sm\\sm_latest\\plugins\\include",
                    "D:\\Code\\sm\\utils",
                    "D:\\Code\\sm\\utils\\",
                    "D:\\Code\\sm\\utils\\chronobreak\\scripting\\include",
                    "D:\\Code\\sm\\utils\\dash\\scripting\\include",
                    "D:\\Code\\sm\\utils\\nmr-objective\\scripting\\include",
                    "D:\\Code\\sm\\utils\\nmr-player\\scripting\\include",
                ],
                "compilerPath": "D:\\Code\\sm\\bin\\sm_latest\\spcomp.exe",
                "outputDirectoryPath": "D:\\Code\\sm\\bin\\plugins_latest\\",
                "compilerArguments": []
            },
            {
                "name": "linux_1_12",
                "includeDirectories": [
                    "./scripting/include",
                    "/home/nmrihserver/sm/ext",
                    "/home/nmrihserver/sm/ext/log4sp/sourcemod/scripting/include",
                    "/home/nmrihserver/sm/ext/ripext/pawn/scripting/include",
                    "/home/nmrihserver/sm/ext/socket/scripting/include",
                    "/home/nmrihserver/sm/ext/SteamWorks/Pawn/includes",
                    "/home/nmrihserver/sm/inc",
                    "/home/nmrihserver/sm/inc/",
                    "/home/nmrihserver/sm/inc/json",
                    "/home/nmrihserver/sm/inc/localizer",
                    "/home/nmrihserver/sm/inc/multicolors/addons/sourcemod/scripting/include",
                    "/home/nmrihserver/sm/inc/nmrih-vscript-proxy",
                    "/home/nmrihserver/sm/inc/outputactions",
                    "/home/nmrihserver/sm/inc/queue/scripting/include",
                    "/home/nmrihserver/sm/inc/smlib2/include",
                    "/home/nmrihserver/sm/sm_1_12/plugins/include",
                    "/home/nmrihserver/sm/utils",
                    "/home/nmrihserver/sm/utils/",
                    "/home/nmrihserver/sm/utils/chronobreak/scripting/include",
                    "/home/nmrihserver/sm/utils/dash/scripting/include",
                    "/home/nmrihserver/sm/utils/nmr-objective/scripting/include",
                    "/home/nmrihserver/sm/utils/nmr-player/scripting/include",
                ],
                "compilerPath": "/home/nmrihserver/sm/bin/sm_1_12/spcomp",
                "outputDirectoryPath": "/home/nmrihserver/sm/bin/plugins_1_12/",
                "compilerArguments": []
            },
            {
                "name": "linux_latest",
                "includeDirectories": [
                    "./scripting/include",
                    "/home/nmrihserver/sm/ext/log4sp/sourcemod/scripting/include",
                    "/home/nmrihserver/sm/ext/ripext/pawn/scripting/include",
                    "/home/nmrihserver/sm/ext/socket/scripting/include",
                    "/home/nmrihserver/sm/ext/SteamWorks/Pawn/includes",
                    "/home/nmrihserver/sm/inc",
                    "/home/nmrihserver/sm/inc/",
                    "/home/nmrihserver/sm/inc/json",
                    "/home/nmrihserver/sm/inc/localizer",
                    "/home/nmrihserver/sm/inc/multicolors/addons/sourcemod/scripting/include",
                    "/home/nmrihserver/sm/inc/nmrih-vscript-proxy",
                    "/home/nmrihserver/sm/inc/outputactions",
                    "/home/nmrihserver/sm/inc/queue/scripting/include",
                    "/home/nmrihserver/sm/inc/smlib2/include",
                    "/home/nmrihserver/sm/sm_latest/plugins/include",
                    "/home/nmrihserver/sm/utils",
                    "/home/nmrihserver/sm/utils/",
                    "/home/nmrihserver/sm/utils/chronobreak/scripting/include",
                    "/home/nmrihserver/sm/utils/dash/scripting/include",
                    "/home/nmrihserver/sm/utils/nmr-objective/scripting/include",
                    "/home/nmrihserver/sm/utils/nmr-player/scripting/include",
                ],
                "compilerPath": "/home/nmrihserver/sm/bin/sm_latest/spcomp",
                "outputDirectoryPath": "/home/nmrihserver/sm/bin/plugins_latest/",
                "compilerArguments": []
            },
        ],
        ```

    - c_cpp_properties.json

        ```
        {
            "configurations": [
                {
                    "name": "Win32",
                    "includePath": [
                        // "${workspaceFolder}/**",
                        // "sm_1_12/public/**",
                        // "sm_1_12/sourcepawn/include/**",
                        "sm_latest/public/**",
                        "sm_latest/sourcepawn/include/**",
                        "ext/log4sp/extern/**",
                        "ext/log4sp/src/**"
                    ],
                    "defines": [
                        "_DEBUG",
                        "UNICODE",
                        "_UNICODE"
                    ],
                    "compilerPath": "C:/Program Files/mingw64/bin/g++.exe",
                    "cStandard": "c11",
                    "cppStandard": "gnu++14",
                    "intelliSenseMode": "windows-gcc-x64"
                }
            ],
            "version": 4
        }
        ```

- 添加插件

    在 plugins 下建立一个单独的文件夹，编写你的插件，建议使用 git，在另一个独立的仓库中管理版本

- 在主项目中添加子模块

    - 添加子模块

        ```shell
        git submodule add <url> <path>

        # 也可以指定子模块的分支
        # 这将自动在 .gitmodules 中设置分支，便于多人合作（仅个人可以只在本地 .git/config 文件中设置）
        git submodule add -b <branch> <url> <path>
        ```

    - 初始化子模块

        ```shell
        cd <submodule path>

        git submodule init
        git submodule update

        # 或者将上面两步合为一步：初始化、抓取并检出子模块
        git submodule update --init

        # 如果子模块内还有子模块，需要进行递归，可以添加 --recursive
        git submodule update --init --recursive
        ```

    - 提交更改（提交添加的子模块）

        ```
        cd ..

        # 查看差异
        git status
        git diff --cached --submodule

        # 提交
        git commit -am "Add module ext/log4sp"
        ```

- 删除子模块

    git 没有提供直接删除子模块的指令，所以需要手动操作
    ```shell
    #删除子模块
    git rm --cached 子模块路径
    git rm -rf 子模块路径
    rm -rf 子模块路径

    从 .gitmodules 删除相关行
    [submodule "path_to_submodule"]
            path = path_to_submodule
            url = https://github.com/path_to_submodule

    从 .git/config 删除相关部分
    [submodule "path_to_submodule"]
        url = https://github.com/path_to_submodule

    rm -rf .git/modules/子模块路径
    ```

- 更新子模块

    - 先提交子模块的修改

        ```shell
        cd <submodule path>
        git add ...
        git commit -m "..."
        git push ...
        ```

    - 或者是拉取子模块远端的新代码

        ```shell
        cd <submodule path>
        git pull origin <branch>
        ```

    - 然后在父项目里更新子模块的引用

        ```shell
        cd ..
        git add <submodule path>
        git commit -m "Bump submodule version"
        git push ...
        ```

- 注意事项

    - 在主项目中从子模块的远端拉取上游修改

        ```shell
        git submodule update --remote <submodulePath>

        # 安全起见，建议在 git submodule update 后面添加 --init 选项
        git submodule update --init --remote <submodulePath>

        # 如果子模块有嵌套的子模块，则应添加 --recursive 选项
        git submodule update --init --recursive --remote <submodulePath>
        ```

    - 如果不小心更新了子模块到最新版本如何回退

        ```shell
        # 查看历史记录
        git log

        # 回退到指定提交 ID
        git checkout <commit id>
        ```

    - 查看子模块信息

        ```shell
        git submodule status
        ```
