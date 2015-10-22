<?php
/**
 * @file
 * This file contains all utility functions that are used with the
 * question entity
 *
 */

/**
 * Loads multiple question entities.
 * @param bool $qids
 * Array of question ids
 * @param array $conditions
 * @param bool $reset
 * @return mixed
 */
function q_and_a_question_load_multiple($qids = FALSE, $conditions = array(), $reset = FALSE) {
  return entity_load('q_and_a_question', $qids, $conditions, $reset);
}

/**
 * A function to call in order to save the question entity
 * @param $entity
 * @return mixed
 */
function q_and_a_question_save(&$entity) {
  return entity_get_controller('q_and_a_question')->save($entity);
}

/**
 * A function to list all questions
 * @return array
 */
function q_and_a_list_questions() {

  $content = array();
  // Load all question entities.
  $entities = q_and_a_question_load_multiple();
  if (!empty($entities)) {
    foreach ($entities as $entity) {
      // Create table rows for our questions.
      $rows[] = array(
        'data' => array(
          'question_title' => $entity->question_title,
          'question' => $entity->question,
          'votes' => $entity->num_votes,
          'answers' => $entity->num_answers,
          'views' => $entity->num_views,
          'view' => l('View', 'q_and_a/question/'.$entity->qid.'/view'),
          'edit' => l('Edit', 'q_and_a/question/'.$entity->qid.'/edit'),
        ),
      );
    }
    // Put our entities into a themed table. See theme_table() for details.
    $content['entity_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => array(t('Title'), t('Question'), t('Votes'), t('Answers'), t('Views'), t('View'), t('Edit')),
    );
  }
  else {
    // No questions message
    $content[] = array(
      '#type' => 'item',
      '#markup' => t('No question entities currently exist.'),
    );
  }
  return $content;
}