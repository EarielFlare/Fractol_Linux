# Fractol_Linux
Fractol project for School42, adapted for Linux. Contains mlx_linux folder.

Проект по фракталам, который можно запустить на Linux. В отличие от проекта на MacOS, содержит папку mlx_linux, в которой лежит дистрибутив MLX для Linux (https://github.com/42Paris/minilibx-linux). Инструкция по работе с ним, а также много другой полезной информации по работе с MLX, взяты по ссылке https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux. Перед запуском make НЕОБХОДИМО запустить скрипт configure из папки mlx_linux.

Проект состоит из двух версий: базовой (mandatory) и продвинутой (bonus). Базовая версия компилируется командой make (make all), продвинутая - командой make bonus. Версии отличаются количеством фракталов, а также возможностью переключения цвета и др. (нажмите H во время работы программы для просмотра опций).

Разница между версией для MacOS и Linux заключается, в основном, в назначении функций-обработчиков событий и keycodes (кодов клавиш клавиатуры). Также изменен Makefile (строки компиляции объектных файлов и сборки бинарника).
