#!/usr/bin/env sh

SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
LIBSTRUI_DIR="${SCRIPT_DIR}/.."

DOCKERFILE="${LIBSTRUI_DIR}/tests/Dockerfile"
IMAGE="libstrui-test"

VOLUME_LOCAL="${LIBSTRUI_DIR}/tests/volume"
VOLUME_DOCKER="/volume"

printf -- "\n-------------------------------------------------\n"
printf -- "-------------------------------------------------\n"
printf "🧪 Testing locally...\n"
printf -- "-------------------------------------------------\n"
printf -- "-------------------------------------------------\n"

(cd "${LIBSTRUI_DIR}/tests" && make) || return 1

printf -- "\n-------------------------------------------------\n"
printf -- "-------------------------------------------------\n"
printf "🏗️  Building Docker image...\n"
printf -- "-------------------------------------------------\n"
printf -- "-------------------------------------------------\n\n"

mkdir -p "${VOLUME_LOCAL}" || return 1

if [ "$1" = "--verbose" ]; then
    docker build -f "${DOCKERFILE}" -t "${IMAGE}" "${LIBSTRUI_DIR}"
else
    docker build -f "${DOCKERFILE}" -t "${IMAGE}" "${LIBSTRUI_DIR}" >/dev/null 2>&1
fi

if [ $? = 0 ]; then
    printf "✅ Image built\n"
else
    printf "❌ Build failed\n"
fi

printf -- "\n-------------------------------------------------\n"
printf -- "-------------------------------------------------\n"
printf "🐳 Testing inside container...\n"
printf -- "-------------------------------------------------\n"
printf -- "-------------------------------------------------\n"

docker run --rm -it "${IMAGE}" bash -c "make"

printf -- "\n-------------------------------------------------\n"
printf -- "-------------------------------------------------\n"
printf "🧹 Cleaning test files...\n"
printf -- "-------------------------------------------------\n"
printf -- "-------------------------------------------------\n\n"

[ -d "${VOLUME_LOCAL}" ] && rm -rf "${VOLUME_LOCAL}"

printf "✅ Done\n"
