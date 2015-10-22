<?php

/**
 * @file
 * This file contains all controller classes for Q&A Entities
 *
 */
class QAndAQuestionController extends DrupalDefaultEntityController {
  /**
   * Create an empty question entity
   * @return object|\stdClass
   */
  public function create() {
    $qa_question = new stdClass();
    $qa_question->qid = 0;
    $qa_question->type = 'q_and_a_question';
    $qa_question->question_title = '';
    $qa_question->question = '';
    $qa_question->num_votes = 0;
    $qa_question->num_views = 0;
    $qa_question->num_answers = 0;

    return $qa_question;
  }

  /**
   * Save
   */
  public function save($entity) {
    //Add created time for new entity
    if (empty($entity->qid)) {
      $entity->created = time();
    }
    $entity->updated = time();

    // Invoke hook_entity_presave().
    module_invoke_all('entity_presave', $entity, 'q_and_a_question');
    // The 'primary_keys' argument determines whether this will be an insert
    // or an update. So if the entity already has an ID, we'll specify
    // basic_id as the key.
    $primary_keys = $entity->qid ? 'qid' : array();
    // Write out the entity record.
    drupal_write_record('q_and_a_questions', $entity, $primary_keys);
    // We're going to invoke either hook_entity_update() or
    // hook_entity_insert(), depending on whether or not this is a
    // new entity. We'll just store the name of hook_entity_insert()
    // and change it if we need to.
    $invocation = 'entity_insert';
    // Now we need to either insert or update the fields which are
    // attached to this entity. We use the same primary_keys logic
    // to determine whether to update or insert, and which hook we
    // need to invoke.
    if (empty($primary_keys)) {
      field_attach_insert('q_and_a_question', $entity);
    }
    else {
      field_attach_update('q_and_a_question', $entity);
      $invocation = 'entity_update';
    }
    // Invoke either hook_entity_update() or hook_entity_insert().
    module_invoke_all($invocation, $entity, 'q_and_a_question');
    return $entity;
  }
}