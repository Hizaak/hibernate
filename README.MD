# Hibernate

## Description

Hibernate est un petit utilitaire écrit en C permettant de mettre en hibernation votre système Linux de manière simple et efficace. Ce programme est conçu pour être utilisé en ligne de commande et peut être utile pour économiser de l'énergie sur des systèmes embarqués ou pour automatiser des tâches. Il a été à l'origine développé car la mise en hibernation de mon ordinateur portable ne fonctionnait pas correctement avec les outils par défaut de ma distribution Linux (Arch Linux/Manjaro, 

## Installation

### Prérequis

Assurez-vous d'avoir les éléments suivants installés sur votre système :

- `gcc` (GNU Compiler Collection) pour la compilation du code C.
- `git` pour cloner le dépôt.

### Installation rapide

Exécutez la commande suivante dans votre terminal pour installer Hibernate en une seule ligne :

```bash
curl -sSL https://raw.githubusercontent.com/hizaak/hibernate/master/install.sh | sudo bash
```

Cette commande télécharge le script d'installation depuis ce dépôt GitHub et l'exécute automatiquement pour installer Hibernate sur votre système. Assurez-vous de comprendre les implications de l'exécution de scripts depuis Internet avant de lancer cette commande.

## Utilisation

Une fois installé, vous pouvez utiliser Hibernate en exécutant la commande suivante dans votre terminal :

```bash
sudo hibernate <state>
```

Voici les états disponibles pour Hibernate :
- freeze / s2idle : Mettre le système en hibernation.
- mem : Mettre le système en hibernation en sauvegardant l'état de la mémoire.
- standby /shallow : Mettre le système en veille prolongée.
- disk : Mettre le système en hibernation en sauvegardant l'état de la mémoire sur le disque.
- deep : Mettre le système en hibernation en sauvegardant l'état de la mémoire sur le disque et en coupant l'alimentation.

Tous les états ne sont pas disponibles sur tous les systèmes. Vous pouvez vérifier les états disponibles sur votre système en exécutant la commande `cat /sys/power/state` dans votre terminal.

Documentation sur les états de veille du noyau Linux :
- [https://www.kernel.org/doc/html/latest/admin-guide/pm/sleep-states.html](https://www.kernel.org/doc/html/latest/admin-guide/pm/sleep-states.html)
- [https://www.kernel.org/doc/Documentation/power/states.txt](https://www.kernel.org/doc/Documentation/power/states.txt)

## Contributions

Les contributions sous forme de rapports de bogues, de demandes d'extraction et d'améliorations sont les bienvenues ! N'hésitez pas à ouvrir une issue ou à envoyer une pull request.