## 项目结构

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

- utils

    以子模块的方式存放工具插件

    这些插件主要用于提供 native 接口给其他插件调用，本身不含复杂的业务逻辑

    与 ext 不同，主要使用 sourcepawn 语言实现

    与 inc 不同，除了头文件还必须添加相关插件，提供的 native 才能正常工作

    tips: 添加新的子模块后，需要配置 settings.json 否则可能找不到头文件
