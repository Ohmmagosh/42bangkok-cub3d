#!/bin/sh

BLK='\033[0;30m'
RED='\033[0;31m'
GRN='\033[0;32m'
YEL='\033[38;5;228m'
BLU='\033[0;34m'
MAG='\033[0;35m'
CYN='\033[0;36m'
WHT='\033[0;37m'
RES='\033[0m'

BLA_filling_bar=('█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '█████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '█████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '██████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '███████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '█████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒' '██████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '███████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒' '████████████████████▒▒▒▒▒▒▒▒▒▒▒▒' \
				 '█████████████████████▒▒▒▒▒▒▒▒▒▒▒' '██████████████████████▒▒▒▒▒▒▒▒▒▒' \
				 '███████████████████████▒▒▒▒▒▒▒▒▒' '████████████████████████▒▒▒▒▒▒▒▒' \
				 '█████████████████████████▒▒▒▒▒▒▒' '██████████████████████████▒▒▒▒▒▒' \
				 '███████████████████████████▒▒▒▒▒' '████████████████████████████▒▒▒▒' \
				 '█████████████████████████████▒▒▒' '██████████████████████████████▒▒' \
				 '███████████████████████████████▒' '████████████████████████████████')


BLA_classic_utf8=( 0.25 '—' "\\" '|' '/' )
BLA_bounce=( 0.3 . · ˙ · )
BLA_vertical_block=( 0.25 ▁ ▂ ▃ ▄ ▅ ▆ ▇ █ █ ▇ ▆ ▅ ▄ ▃ ▂ ▁ )
BLA_horizontal_block=( 0.25 ▏ ▎ ▍ ▌ ▋ ▊ ▉ ▉ ▊ ▋ ▌ ▍ ▎ ▏ )
BLA_quarter=( 0.25 ▖ ▘ ▝ ▗ )
BLA_triangle=( 0.45 ◢ ◣ ◤ ◥)
BLA_semi_circle=( 0.1 ◐ ◓ ◑ ◒ )
BLA_rotating_eyes=( 0.4 ◡◡ ⊙⊙ ⊙⊙ ◠◠ )
BLA_firework=( 0.4 '⢀' '⠠' '⠐' '⠈' '*' '*' ' ' )
BLA_braille=( 0.2 ⠁ ⠂ ⠄ ⡀ ⢀ ⠠ ⠐ ⠈ )
BLA_braille_whitespace=( 0.2 ⣾ ⣽ ⣻ ⢿ ⡿ ⣟ ⣯ ⣷ )
BLA_trigram=( 0.25 ☰ ☱ ☳ ☶ ☴ )
BLA_arrow=( 0.15 ▹▹▹▹▹ ▸▹▹▹▹ ▹▸▹▹▹ ▹▹▸▹▹ ▹▹▹▸▹ ▹▹▹▹▸ ▹▹▹▹▹ ▹▹▹▹▹ ▹▹▹▹▹ ▹▹▹▹▹ ▹▹▹▹▹ ▹▹▹▹▹ ▹▹▹▹▹ )
BLA_bouncing_ball=( 0.4 '(●     )' '( ●    )' '(  ●   )' '(   ●  )' '(    ● )' '(     ●)' '(    ● )' '(   ●  )' '(  ●   )' '( ●    )' )
BLA_big_dot=( 0.7 ∙∙∙ ●∙∙ ∙●∙ ∙∙● )
BLA_modern_metro=( 0.15 ▰▱▱▱▱▱▱ ▰▰▱▱▱▱▱ ▰▰▰▱▱▱▱ ▱▰▰▰▱▱▱ ▱▱▰▰▰▱▱ ▱▱▱▰▰▰▱ ▱▱▱▱▰▰▰ ▱▱▱▱▱▰▰ ▱▱▱▱▱▱▰ ▱▱▱▱▱▱▱ ▱▱▱▱▱▱▱ ▱▱▱▱▱▱▱ ▱▱▱▱▱▱▱ )
BLA_pong=( 0.35 '▐⠂       ▌' '▐⠈       ▌' '▐ ⠂      ▌' '▐ ⠠      ▌' '▐  ⡀     ▌' '▐  ⠠     ▌' '▐   ⠂    ▌' '▐   ⠈    ▌' '▐    ⠂   ▌' '▐    ⠠   ▌' '▐     ⡀  ▌' '▐     ⠠  ▌' '▐      ⠂ ▌' '▐      ⠈ ▌' '▐       ⠂▌' '▐       ⠠▌' '▐       ⡀▌' '▐      ⠠ ▌' '▐      ⠂ ▌' '▐     ⠈  ▌' '▐     ⠂  ▌' '▐    ⠠   ▌' '▐    ⡀   ▌' '▐   ⠠    ▌' '▐   ⠂    ▌' '▐  ⠈     ▌' '▐  ⠂     ▌' '▐ ⠠      ▌' '▐ ⡀      ▌' '▐⠠       ▌' )
BLA_earth=( 0.45 🌍 🌎 🌏 )
BLA_clock=( 0.2 🕛 🕐 🕑 🕒 🕓 🕔 🕕 🕖 🕗 🕘 🕙 🕚 )
BLA_moon=( 0.8 🌑 🌒 🌓 🌔 🌕 🌖 🌗 🌘 )
BLA_orange_pulse=( 0.35 🔸 🔶 🟠 🟠 🔶 )
BLA_blue_pulse=( 0.35 🔹 🔷 🔵 🔵 🔷 )
BLA_football=( 0.25 ' 👧⚽️       👦' '👧  ⚽️      👦' '👧   ⚽️     👦' '👧    ⚽️    👦' '👧     ⚽️   👦' '👧      ⚽️  👦' '👧       ⚽️👦 ' '👧      ⚽️  👦' '👧     ⚽️   👦' '👧    ⚽️    👦' '👧   ⚽️     👦' '👧  ⚽️      👦' )
BLA_blink=( 0.25 😐 😐 😐 😐 😐 😐 😐 😐 😐 😑 )
BLA_camera=( 0.1 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📷 📸 📷 📸 )
BLA_sparkling_camera=( 0.1 '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📷 ' '📸✨' '📷 ' '📸✨' )
BLA_sick=( 0.9 🤢 🤢 🤮 )
BLA_monkey=( 0.4 🙉 🙈 🙊 🙈 )
BLA_bomb=( 0.25 '💣   ' ' 💣  ' '  💣 ' '   💣' '   💣' '   💣' '   💣' '   💣' '   💥' '    ' '    ' )

animation () {
	for i in ${BLA_filling_bar[@]}; do
		echo -ne "\r${GRN}$i${RES}\r";
	done
	printf "\n"
}

for i in $@ ; do
	echo -e "$i";
	animation;
	sleep 0.02;
done


#animation
