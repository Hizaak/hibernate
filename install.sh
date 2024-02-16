#!/bin/bash

url="https://github.com/hizaak/hibernate.git"

# Vérifier si l'utilisateur est root
if [ "$(id -u)" -ne 0 ]; then
    echo "Ce script nécessite des privilèges root pour être exécuté."
    exit 1
fi

# Vérifier si le paquet git est installé
if ! command -v git &> /dev/null; then
    echo "Git n'est pas installé."
    exit 1
fi

# Vérifier que le paquet gcc est installé, mais sans dpkg car il n'est pas installé par défaut sur les systèmes non basés sur Debian
if ! command -v gcc &> /dev/null; then
    echo "GCC n'est pas installé."
    exit 1
fi

# Cloner le dépôt
if ! git clone $url; then
    echo "Le clonage du dépôt a échoué."
    exit 1
else
    echo "Le dépôt a été cloné avec succès."
fi

cd hibernate || exit 1

# Vérifier si le script hibernate.c existe
if [ ! -f hibernate.c ]; then
    echo "Le fichier hibernate.c n'existe pas."
    exit 1
fi


# Compiler le script hibernate.c
if ! gcc hibernate.c -o hibernate; then
    echo "La compilation du script a échoué."
    exit 1
else
    echo "Le script a été compilé avec succès."
fi

# Vérifier si la copie s'est bien déroulée
if ! cp hibernate /usr/bin/; then
    echo "La copie du script a échoué."
    exit 1
else
    echo "Le script a été copié avec succès."
fi

# Supprimer le dossier hibernate
cd .. || exit 1

if ! rm -rf hibernate; then
    echo "La suppression du dossier hibernate a échoué."
    exit 1
else
    echo "Le dossier hibernate a été supprimé avec succès."
fi

echo "Le script a été installé avec succès."